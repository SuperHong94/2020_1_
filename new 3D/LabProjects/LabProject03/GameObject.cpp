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
		m_pMesh->Render(hDCFrameBuffer);
		::SelectObject(hDCFrameBuffer, hOldPen);
		::DeleteObject(hPen);
	}
}


CBullet::CBullet(const XMFLOAT3& playerPos) :startPos{ playerPos }, nowPos{ playerPos }
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

	nowPos.x = m_xmf4x4World._41;
	nowPos.y = m_xmf4x4World._42;
	nowPos.z = m_xmf4x4World._43;
}


XMFLOAT3& CGameObject::GetPosition() const
{
	return XMFLOAT3(m_xmf4x4World._41, m_xmf4x4World._42, m_xmf4x4World._43);
}



XMFLOAT3& CBullet::GetStartPos()
{
	return startPos;
}