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



//8주차 이전내용
//CPoint3D CGameObject::WorldTransform(CPoint3D& f3Model)
//{
//	float fPitch = DegreeToRadian(m_fRotation.x);
//	float fYaw = DegreeToRadian(m_fRotation.y);
//	float fRoll = DegreeToRadian(m_fRotation.z);
//	CPoint3D f3World = f3Model;
//	CPoint3D f3Rotated = f3Model;
//	if (fPitch != 0.0f)
//	{
//
//		/*	f3Rotated.y = float(f3World.y * cos(fPitch) - f3World.z * sin(fPitch));
//			f3Rotated.z = float(f3World.y * sin(fPitch) + f3World.z * cos(fPitch));
//			f3World.y = f3Rotated.y;
//			f3World.z = f3Rotated.z;*/
//		XMFLOAT3 pos = f3Rotated.ToXMFLOAT3();
//		XMFLOAT4X4 Matrix;
//		Matrix._11 = 1.0f; Matrix._12 = 0.0f; Matrix._13 = 0.0f, Matrix._14 = 0.0f;
//		Matrix._21 = 0.0f; Matrix._22 = cos(fPitch); Matrix._23 = sin(fPitch); Matrix._24 = 0.0f;
//		Matrix._31 = 0.0f; Matrix._32 = -sin(fPitch); Matrix._33 = cos(fPitch); Matrix._34 = 0.0f;
//		Matrix._41 = 0.0f; Matrix._42 = 0.0f; Matrix._43 = 0.0f; Matrix._44 = 1.0f;
//
//		XMStoreFloat3(&pos, XMVector3Transform(XMLoadFloat3(&pos), XMLoadFloat4x4(&Matrix)));
//		f3World = pos;
//	}
//	if (fYaw != 0.0f)
//	{
//		/*f3Rotated.x = float(f3World.x * cos(fYaw) + f3World.z * sin(fYaw));
//		f3Rotated.z = float(-f3World.x * sin(fYaw) + f3World.z * cos(fYaw));
//		f3World.x = f3Rotated.x;
//		f3World.z = f3Rotated.z;*/
//		XMFLOAT3 pos = f3Rotated.ToXMFLOAT3();
//		XMFLOAT4X4 Matrix;
//		Matrix._11 = cos(fYaw); Matrix._12 = 0.0f; Matrix._13 = -sin(fYaw), Matrix._14 = 0.0f;
//		Matrix._21 = 0.0f; Matrix._22 = 1.0f; Matrix._23 = 0.0; Matrix._24 = 0.0f;
//		Matrix._31 = sin(fYaw); Matrix._32 = 0.0; Matrix._33 = cos(fYaw); Matrix._34 = 0.0f;
//		Matrix._41 = 0.0f; Matrix._42 = 0.0f; Matrix._43 = 0.0f; Matrix._44 = 1.0f;
//
//		XMStoreFloat3(&pos, XMVector3Transform(XMLoadFloat3(&pos), XMLoadFloat4x4(&Matrix)));
//		f3World = pos;
//	}
//	if (fRoll != 0.0f)
//	{
//		/*f3Rotated.x = float(f3World.x * cos(fRoll) - f3World.y * sin(fRoll));
//		f3Rotated.y = float(f3World.x * sin(fRoll) + f3World.y * cos(fRoll));
//		f3World.x = f3Rotated.x;
//		f3World.y = f3Rotated.y;*/
//		XMFLOAT3 pos = f3Rotated.ToXMFLOAT3();
//		XMFLOAT4X4 Matrix;
//		Matrix._11 = cos(fRoll); Matrix._12 = sin(fRoll); Matrix._13 = 0.0f, Matrix._14 = 0.0f;
//		Matrix._21 = -sin(fRoll); Matrix._22 = cos(fRoll); Matrix._23 = 0.0f; Matrix._24 = 0.0f;
//		Matrix._31 = 0.0f; Matrix._32 = 0.0f; Matrix._33 = 1.0f; Matrix._34 = 0.0f;
//		Matrix._41 = 0.0f; Matrix._42 = 0.0f; Matrix._43 = 0.0f; Matrix._44 = 1.0f;
//
//		XMStoreFloat3(&pos, XMVector3Transform(XMLoadFloat3(&pos), XMLoadFloat4x4(&Matrix)));
//		f3World = pos;
//	}
//	XMFLOAT3 pos = f3World.ToXMFLOAT3();
//	XMStoreFloat3(&pos, XMVector3Transform(XMLoadFloat3(&pos), XMMatrixTranslation(m_fPosition.x, m_fPosition.y, m_fPosition.z)));
//	
//	f3World = pos;
//
//	return(f3World);
//}
//
//void CGameObject::Animate(float fElapsedTime)
//{
//	Rotate(m_fRotationSpeed.x * fElapsedTime, m_fRotationSpeed.y * fElapsedTime, m_fRotationSpeed.z * fElapsedTime);
//}
//
//void CGameObject::Render(HDC hDCFrameBuffer)
//{
//	HPEN hPen = ::CreatePen(PS_SOLID, 0, m_dwColor);
//	HPEN hOldPen = (HPEN)::SelectObject(hDCFrameBuffer, hPen);
//
//	if (m_pMesh) m_pMesh->Render(hDCFrameBuffer);
//
//	::SelectObject(hDCFrameBuffer, hOldPen);
//	::DeleteObject(hPen);
//}
