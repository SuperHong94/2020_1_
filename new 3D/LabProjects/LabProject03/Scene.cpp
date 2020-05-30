#include "stdafx.h"
#include "Scene.h"
#include "GraphicsPipeline.h"

void CScene::BuildObjects()
{



	m_nObjects = 7;
	m_ppObjects = new CExplosion * [m_nObjects];
	for (int i = 0; i < m_nObjects; ++i) {
		m_ppObjects[i] = new CExplosion();
	}

	m_nMap = 20;
	m_pMap = new CMap * [m_nMap];

	CMapMesh* pMapMesh = new CMapMesh();
	float startPos = (-m_nMap * 0.5f) * MAPDEPTH;
	for (int i = 0; i < m_nMap; ++i) {
		m_pMap[i] = new CMap();
		m_pMap[i]->SetMesh(pMapMesh);
		m_pMap[i]->SetColor(RGB(0, 0, 0));
		m_pMap[i]->SetRotationSpeed(0.0f);
		m_pMap[i]->SetPosition(0.0f, 0.0f, 0.0f);
		m_pMap[i]->SetMovingSpeed(0.0f);
		m_pMap[i]->SetPosition(0.0f, 0.0f, startPos + MAPDEPTH);

		startPos += MAPDEPTH;

	}

}


void CScene::ReleaseObjects()
{
	for (int i = 0; i < m_nObjects; i++) {
		if (m_ppObjects[i])
			delete m_ppObjects[i];
	}

	if (m_ppObjects) delete[] m_ppObjects;
}



void CScene::Animate(float fElapsedTime)
{
	float halfWidth = MAPWIDTH * 0.5f;
	float halfHeight = MAPHEIGHT * 0.5f;
	IsCollision();
	for (int i = 0; i < m_nObjects; i++) {
		IsCollision(m_ppObjects[i]);
		XMFLOAT3 pos = m_ppObjects[i]->GetPosition();
		if (pos.x <= -halfWidth || pos.y >= halfHeight || pos.x >= halfWidth || pos.y <= -halfHeight ||
			pos.z >= 100.0f || pos.z <= -100.0f)
			m_ppObjects[i]->SetMovingDirection(m_ppObjects[i]->GetMovieReverseDir());
		m_ppObjects[i]->Animate(fElapsedTime);
	}

	XMFLOAT3 pos = m_pPlayer->GetPosition();

	if (pos.x <= -halfWidth || pos.y >= halfHeight || pos.x >= halfWidth || pos.y <= -halfHeight ||
		pos.z >= 10.0f || pos.z <= -10.0f) {
		m_pPlayer->SetPosition(0.0f, 0.0f, 0.0f);
		m_pPlayer->SetCameraOffset(XMFLOAT3(0.0f, 5.0f, -15.0f));
	}
}

void CScene::Render(HDC hDCFrameBuffer, CCamera* pCamera)
{
	CGraphicsPipeline::SetViewport(&pCamera->m_Viewport);
	CGraphicsPipeline::SetViewProjectTransform(&pCamera->m_xmf4x4ViewProject);
	bool bIsVisible;


	//bIsVisible = m_pMap->IsVisible(pCamera);
	//if (bIsVisible) 
	for (int i = 0; i < m_nMap; ++i)
		m_pMap[i]->Render(hDCFrameBuffer, pCamera);

	for (int i = 0; i < m_nObjects; i++) {
		//bIsVisible = m_ppObjects[i]->IsVisible(pCamera);
		//if (bIsVisible) 
		m_ppObjects[i]->Render(hDCFrameBuffer, pCamera);

	}
}



bool CScene::IsCollision() {
	bool IsContains = false;
	for (int iBullet = 0; iBullet < m_pPlayer->curBulletCount; ++iBullet) {
		CBullet* pBullet = m_pPlayer->bullets[iBullet];

		BoundingBox xmbbModel = pBullet->m_pMesh->m_xmBoundingBox;
		xmbbModel.Transform(xmbbModel, XMLoadFloat4x4(&pBullet->m_xmf4x4World));
		if (pBullet->m_bActive) {
			for (int iExplosion = 0; iExplosion < m_nObjects; ++iExplosion) {
				if (m_ppObjects[iExplosion]->m_bActive) {
					BoundingBox other = m_ppObjects[iExplosion]->m_pMesh->m_xmBoundingBox;
					other.Transform(other, XMLoadFloat4x4(m_ppObjects[iExplosion]->GetWorldMatrix()));
					if (xmbbModel.Contains(other) != DirectX::DISJOINT) {
						m_ppObjects[iExplosion]->SetParticlePosition();
						m_ppObjects[iExplosion]->m_bActive = false;
						pBullet->m_bActive = false;
						m_pPlayer->SetTarget(nullptr);
						IsContains = true;
					}
				}
			}
		}
	}
	return IsContains;
}

bool CScene::IsCollision(CExplosion* pObject) {
	bool IsContains = false;

	BoundingBox xmbbModel = pObject->m_pMesh->m_xmBoundingBox;
	xmbbModel.Transform(xmbbModel, XMLoadFloat4x4(&pObject->m_xmf4x4World));
	if (pObject->m_bActive) {
		for (int i = 0; i < m_nObjects; ++i) {
			if (m_ppObjects[i]->m_bActive) {
				BoundingBox other = m_ppObjects[i]->m_pMesh->m_xmBoundingBox;
				other.Transform(other, XMLoadFloat4x4(m_ppObjects[i]->GetWorldMatrix()));
				if (xmbbModel.Contains(other) != DirectX::DISJOINT) {
					m_ppObjects[i]->SetMovingDirection(m_ppObjects[i]->GetMovieReverseDir());
					pObject->SetMovingDirection(pObject->GetMovieReverseDir());
					IsContains = true;
					return IsContains;
				}
			}
		}
	}

	return IsContains;
}


bool CScene::IsCollision(XMFLOAT3 ray)
{
	bool IsContains = false;
	//XMFLOAT4X4 camera4x4 = m_pPlayer->GetCamera()->m_xmf4x4View;
	//float worldX = (ray.x - ray.y * camera4x4._21 - camera4x4._31) / camera4x4._11;
	//float worldY = (ray.y - ray.x * camera4x4._12 - camera4x4._32) / camera4x4._22;
	//float worldZ = (ray.z - ray.x * camera4x4._13 - ray.y * camera4x4._23) / camera4x4._33;*/


	for (int i = 0; i < m_nObjects; ++i) {
		if (m_ppObjects[i]->m_bActive) {
			BoundingBox other = m_ppObjects[i]->m_pMesh->m_xmBoundingBox;
			other.Transform(other, XMLoadFloat4x4(m_ppObjects[i]->GetWorldMatrix()));
			other.Transform(other, XMLoadFloat4x4(&m_pPlayer->GetCamera()->m_xmf4x4View));
			if (other.Contains(XMLoadFloat3(&ray)) != DirectX::DISJOINT) {
				m_ppObjects[i]->SetColor(RGB(0, 0, 0));
				m_pPlayer->SetTarget(m_ppObjects[i]);
				IsContains = true;
				return IsContains;
			}
		}
	}
	return IsContains;
}


int CScene::GetObjectsCount()
{
	return m_nObjects;
}



bool CScene::IsPickingObject(int x, int y, CCamera* pCamera)
{
	bool isPicking = false;
	XMFLOAT3 ralyDir = XMFLOAT3(0.0f, 0.0f, 0.0f); //광선방향


	float fHalfWidth = pCamera->m_Viewport.m_nWidth * 0.5;
	float fHalfHeight = pCamera->m_Viewport.m_nHeight * 0.5;

	//투영변환후의 x좌표
	float projectX = (x - fHalfWidth - pCamera->m_Viewport.m_nLeft) / fHalfWidth;
	float projectY = -1.0f * ((y - pCamera->m_Viewport.m_nTop - fHalfHeight) / fHalfHeight);


	//투영변환 전의 카메라좌표계의 좌표
	float cameraX = projectX / pCamera->m_xmf4x4Project._11;
	float cameraY = projectY / pCamera->m_xmf4x4Project._22;
	float cameraZ = 1.0f;


	ralyDir = XMFLOAT3(cameraX, cameraY, cameraZ); //광선방향
	XMStoreFloat3(&ralyDir, XMVector2Normalize(XMLoadFloat3(&ralyDir)));
	XMFLOAT3 ray;
	float maxDis = 500.0f; //광선최대거리

	for (float i = maxDis; i > 0.0f; i -= 0.01f) {
		XMStoreFloat3(&ray, XMVectorScale(XMLoadFloat3(&ralyDir), i));
		//std::cout << ray.x << ' ' << ray.y << ' ' << ray.z << std::endl;
		isPicking = IsCollision(ray);
	}
	return isPicking;
}

void CScene::AllFire()
{
	for (int i = 0; i < m_nObjects; ++i) {
		m_ppObjects[i]->SetParticlePosition();
		m_ppObjects[i]->m_bActive = false;
	}
}