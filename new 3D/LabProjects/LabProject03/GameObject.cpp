#include "stdafx.h"
#include "GameObject.h"
#include "GraphicsPipeline.h" //8주차 추가

//8주차 소멸자 수정
//CGameObject::~CGameObject(void)
//{
//	if (m_pMesh) m_pMesh->Release();
//}
CGameObject::~CGameObject()
{
	if (m_pMesh) m_pMesh->Release();
}
//--------------


//8주차 추가사항
void CGameObject::SetPosition(float x, float y, float z)
{
	m_xmf4x4World._41 = x;
	m_xmf4x4World._42 = y;
	m_xmf4x4World._43 = z;
}
void CGameObject::SetPosition(XMFLOAT3& xmf3Position)
{
	m_xmf4x4World._41 = xmf3Position.x;
	m_xmf4x4World._42 = xmf3Position.y;
	m_xmf4x4World._43 = xmf3Position.z;
}
void CGameObject::SetMovingDirection(XMFLOAT3& xmf3MovingDirection)
{
	XMStoreFloat3(&m_xmf3MovingDirection,
		XMVector3Normalize(XMLoadFloat3(&xmf3MovingDirection)));
}

void CGameObject::SetRotationAxis(XMFLOAT3& xmf3RotationAxis)
{
	XMStoreFloat3(&m_xmf3RotationAxis,
		XMVector3Normalize(XMLoadFloat3(&xmf3RotationAxis)));
}


void CGameObject::Rotate(float fPitch, float fYaw, float fRoll)
{
	XMMATRIX xmmtxRotate =
		XMMatrixRotationRollPitchYaw(XMConvertToRadians(fPitch),
			XMConvertToRadians(fYaw), XMConvertToRadians(fRoll));
	XMStoreFloat4x4(&m_xmf4x4World, XMMatrixMultiply(xmmtxRotate,
		XMLoadFloat4x4(&m_xmf4x4World)));
}
//회전축을 중심으로 회전, 왼손좌표계에서 회전(자전) 행렬은 평행이동 행렬 왼쪽에 곱해야 한다. 
void CGameObject::Rotate(XMFLOAT3& xmf3RotationAxis, float fAngle)
{
	XMMATRIX xmmtxRotate =
		XMMatrixRotationAxis(XMLoadFloat3(&xmf3RotationAxis),
			XMConvertToRadians(fAngle));
	XMStoreFloat4x4(&m_xmf4x4World, XMMatrixMultiply(xmmtxRotate,
		XMLoadFloat4x4(&m_xmf4x4World)));
}


void CGameObject::Move(XMFLOAT3& vDirection, float fSpeed)
{
	SetPosition(m_xmf4x4World._41 + vDirection.x * fSpeed,
		m_xmf4x4World._42 + vDirection.y * fSpeed, m_xmf4x4World._43 +
		vDirection.z * fSpeed);
}

void CGameObject::Animate(float fElapsedTime)
{
	if (m_fRotationSpeed != 0.0f) Rotate(m_xmf3RotationAxis,
		m_fRotationSpeed * fElapsedTime);
	if (m_fMovingSpeed != 0.0f) Move(m_xmf3MovingDirection,
		m_fMovingSpeed * fElapsedTime);

}

void CGameObject::Render(HDC hDCFrameBuffer, CCamera* pCamera)
{
	if (m_pMesh)
	{
		CGraphicsPipeline::SetWorldTransform(&m_xmf4x4World);
		HPEN hPen = ::CreatePen(PS_SOLID, 0, m_dwColor);
		HPEN hOldPen = (HPEN)::SelectObject(hDCFrameBuffer, hPen);

		m_pMesh->Render(hDCFrameBuffer, pCamera);
		::SelectObject(hDCFrameBuffer, hOldPen);
		::DeleteObject(hPen);
	}

}


CBullet::CBullet(const XMFLOAT3& playerPos)
{
	SetPosition(XMFLOAT3(playerPos));
}
CBullet::~CBullet()
{
}
void CBullet::Move(XMFLOAT3& vDirection, float fSpeed)
{
	SetPosition(m_xmf4x4World._41 + vDirection.x * fSpeed,
		m_xmf4x4World._42 + vDirection.y * fSpeed, m_xmf4x4World._43 +
		vDirection.z * fSpeed);
}



XMFLOAT3& CGameObject::GetPosition() const
{
	XMFLOAT3 Pos = XMFLOAT3(m_xmf4x4World._41, m_xmf4x4World._42, m_xmf4x4World._43);
	return Pos;
}



bool CGameObject::IsVisible(CCamera* pCamera)
{

	if (m_pMesh) {
		BoundingBox xmbbModel = m_pMesh->m_xmBoundingBox;
		xmbbModel.Transform(xmbbModel, XMLoadFloat4x4(&m_xmf4x4World));
		bool bIsVisible = pCamera->IsInFrustum(xmbbModel);
		return (bIsVisible);
	}

}




XMFLOAT4X4* CGameObject::GetWorldMatrix()
{
	return &m_xmf4x4World;
}



//---폭발 오브젝트 만들기

CExplosion::CExplosion() 
{
	std::default_random_engine dre;
	std::uniform_real_distribution uid(-10.0f,10.0f);
	XMFLOAT3 pos = GetPosition();
	startPos = pos;
	SetPosition(pos);
	explorObjects = new CGameObject * [m_explosionCount];
	CCubeMesh* pCubeMesh = new CCubeMesh(1.0f, 1.0f, 1.0f);
	XMFLOAT3 dir;
	for (int i = 0; i < m_explosionCount; ++i) {
		explorObjects[i] = new CGameObject;
		XMStoreFloat3(&dir, XMVector4Normalize(XMVectorSet(uid(dre), uid(dre), uid(dre), uid(dre))));
		explorObjects[i]->SetPosition(pos);
		explorObjects[i]->SetMesh(pCubeMesh);
		explorObjects[i]->SetColor(RGB(255, 255, 0));

		explorObjects[i]->SetMovingDirection(dir);
		explorObjects[i]->SetMovingSpeed(50.0f);
	}

}

void CExplosion::Animate(float fTimeElapsed) {
	if (m_bActive) {
		CGameObject::Animate(fTimeElapsed);
	}
	else {

		for (int i = 0; i < m_explosionCount; ++i)
			explorObjects[i]->Animate(fTimeElapsed);

		XMFLOAT3 dis;
		XMStoreFloat3(&dis, XMVector3Length(XMVectorSubtract(XMLoadFloat3(&startPos),
			XMLoadFloat3(&explorObjects[0]->GetPosition()))));
		if (dis.x> 20.0f){
			m_bActive = true;
			m_dwColor = OriginalColor;
		}
	}

}
void CExplosion::Render(HDC hDCFrameBuffer, CCamera* pCamera)
{
	if (m_bActive) {
		CGameObject::Render(hDCFrameBuffer, pCamera);
	}
	else {
		for (int i = 0; i < m_explosionCount; ++i){
			explorObjects[i]->Render(hDCFrameBuffer, pCamera);
		}
	}

}

void CExplosion::SetParticlePosition()
{
	XMFLOAT3 pos = GetPosition();
	startPos = pos;
	for (int i = 0; i < m_explosionCount; ++i)
	{
		
		explorObjects[i]->SetPosition(pos);
	}
}