#include "stdafx.h"
#include "Scene.h"
#include "GraphicsPipeline.h"

void CScene::BuildObjects()
{

	CCubeMesh* pCubeMesh = new CCubeMesh(4.0f, 4.0f, 4.0f);

	m_nObjects = 5;
	m_ppObjects = new CExplosion * [m_nObjects];
	m_ppObjects[0] = new CExplosion();
	m_ppObjects[0]->SetMesh(pCubeMesh);
	m_ppObjects[0]->SetColor(RGB(255, 0, 0));
	m_ppObjects[0]->OriginalColor = RGB(255, 0, 0);
	m_ppObjects[0]->SetPosition(-13.5f, 0.0f, +14.0f);
	m_ppObjects[0]->SetRotationAxis(XMFLOAT3(1.0f, 1.0f, 0.0f));
	m_ppObjects[0]->SetRotationSpeed(90.0f);
	m_ppObjects[0]->SetMovingDirection(XMFLOAT3(1.0f, 0.0f, 0.0f));
	m_ppObjects[0]->SetMovingSpeed(0.5f);
	m_ppObjects[1] = new CExplosion();
	m_ppObjects[1]->SetMesh(pCubeMesh);
	m_ppObjects[1]->SetColor(RGB(0, 0, 255));
	m_ppObjects[1]->OriginalColor=RGB(0, 0, 255);
	m_ppObjects[1]->SetPosition(+13.5f, 0.0f, +14.0f);
	m_ppObjects[1]->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 1.0f));
	m_ppObjects[1]->SetRotationSpeed(180.0f);
	m_ppObjects[1]->SetMovingDirection(XMFLOAT3(-1.0f, 0.0f, 0.0f));
	m_ppObjects[1]->SetMovingSpeed(1.5f);
	m_ppObjects[2] = new CExplosion();
	m_ppObjects[2]->SetMesh(pCubeMesh);
	m_ppObjects[2]->SetColor(RGB(0, 255, 0));
	m_ppObjects[2]->OriginalColor = RGB(0, 255, 0);
	m_ppObjects[2]->SetPosition(0.0f, +5.0f, 20.0f);
	m_ppObjects[2]->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 1.0f));
	m_ppObjects[2]->SetRotationSpeed(30.15f);
	m_ppObjects[2]->SetMovingDirection(XMFLOAT3(1.0f, -1.0f, 0.0f));
	m_ppObjects[2]->SetMovingSpeed(0.0f);
	m_ppObjects[3] = new CExplosion();
	m_ppObjects[3]->SetMesh(pCubeMesh);
	m_ppObjects[3]->SetColor(RGB(0, 255, 255));
	m_ppObjects[3]->OriginalColor = RGB(0, 255, 255);
	m_ppObjects[3]->SetPosition(0.0f, 0.0f, 40.0f);
	m_ppObjects[3]->SetPosition(0.0f, 0.0f, 40.0f);
	m_ppObjects[3]->SetRotationAxis(XMFLOAT3(0.0f, 0.0f, 1.0f));
	m_ppObjects[3]->SetRotationSpeed(40.6f);
	m_ppObjects[3]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, 1.0f));
	m_ppObjects[3]->SetMovingSpeed(0.0f);
	m_ppObjects[4] = new CExplosion();
	m_ppObjects[4]->SetMesh(pCubeMesh);
	m_ppObjects[4]->SetColor(RGB(128, 0, 255));
	m_ppObjects[4]->OriginalColor = RGB(128, 0, 255);
	m_ppObjects[4]->SetPosition(10.0f, 10.0f, 50.0f);
	m_ppObjects[4]->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 1.0f));
	m_ppObjects[4]->SetRotationSpeed(50.06f);
	m_ppObjects[4]->SetMovingDirection(XMFLOAT3(0.0f, 1.0f, 1.0f));
	m_ppObjects[4]->SetMovingSpeed(0.0f);
	m_pMap = new CMap();
	CMapMesh* pMapMesh = new CMapMesh();
	m_pMap->SetMesh(pMapMesh);
	m_pMap->SetColor(RGB(0, 0, 0));
	m_pMap->SetRotationSpeed(0.0f);
	m_pMap->SetPosition(0.0f, 0.0f, 0.0f);
	m_pMap->SetMovingSpeed(0.0f);

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
	IsCollision();
	for (int i = 0; i < m_nObjects; i++) {
		m_ppObjects[i]->Animate(fElapsedTime);
	}
}

void CScene::Render(HDC hDCFrameBuffer, CCamera* pCamera)
{
	CGraphicsPipeline::SetViewport(&pCamera->m_Viewport);
	CGraphicsPipeline::SetViewProjectTransform(&pCamera->m_xmf4x4ViewProject);
	bool bIsVisible;
	bIsVisible = m_pMap->IsVisible(pCamera);
	if (bIsVisible)
		m_pMap->Render(hDCFrameBuffer, pCamera);

	for (int i = 0; i < m_nObjects; i++) {
		bIsVisible = m_ppObjects[i]->IsVisible(pCamera);
		if (bIsVisible) {
			m_ppObjects[i]->Render(hDCFrameBuffer, pCamera);
		}
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
				m_ppObjects[i]->SetColor(RGB(255, 255, 255));
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
	float projectX =( x-fHalfWidth- pCamera->m_Viewport.m_nLeft)/fHalfWidth;
	float projectY= -1.0f*((y- pCamera->m_Viewport.m_nTop-fHalfHeight)/fHalfHeight);


	//투영변환 전의 카메라좌표계의 좌표
	float cameraX = projectX / pCamera->m_xmf4x4Project._11;
	float cameraY = projectY / pCamera->m_xmf4x4Project._22;
	float cameraZ = 1.0f;

	
	ralyDir = XMFLOAT3(cameraX, cameraY, cameraZ); //광선방향
	XMStoreFloat3(&ralyDir, XMVector2Normalize(XMLoadFloat3(&ralyDir)));
	XMFLOAT3 ray;
	float maxDis = 500.0f; //광선최대거리

	for (float i = maxDis; i > 0.0f; i-=0.01f) {
		XMStoreFloat3(&ray, XMVectorScale(XMLoadFloat3(&ralyDir), i));
		//std::cout << ray.x << ' ' << ray.y << ' ' << ray.z << std::endl;
		isPicking=IsCollision(ray);
	}
	return isPicking;
}