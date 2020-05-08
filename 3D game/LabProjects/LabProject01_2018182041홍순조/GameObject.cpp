#include "stdafx.h"
#include "GameObject.h"

CGameObject::~CGameObject(void)
{
	if (m_pMesh) m_pMesh->Release();
}

CPoint3D CGameObject::WorldTransform(CPoint3D& f3Model)
{
	float fPitch = DegreeToRadian(m_fRotation.x);
	float fYaw = DegreeToRadian(m_fRotation.y);
	float fRoll = DegreeToRadian(m_fRotation.z);
	CPoint3D f3World = f3Model;
	CPoint3D f3Rotated = f3Model;
	if (fPitch != 0.0f)
	{

		/*	f3Rotated.y = float(f3World.y * cos(fPitch) - f3World.z * sin(fPitch));
			f3Rotated.z = float(f3World.y * sin(fPitch) + f3World.z * cos(fPitch));
			f3World.y = f3Rotated.y;
			f3World.z = f3Rotated.z;*/
		XMFLOAT3 pos = f3Rotated.ToXMFLOAT3();
		XMFLOAT4X4 Matrix;
		Matrix._11 = 1.0f; Matrix._12 = 0.0f; Matrix._13 = 0.0f, Matrix._14 = 0.0f;
		Matrix._21 = 0.0f; Matrix._22 = cos(fPitch); Matrix._23 = sin(fPitch); Matrix._24 = 0.0f;
		Matrix._31 = 0.0f; Matrix._32 = -sin(fPitch); Matrix._33 = cos(fPitch); Matrix._34 = 0.0f;
		Matrix._41 = 0.0f; Matrix._42 = 0.0f; Matrix._43 = 0.0f; Matrix._44 = 1.0f;

		XMStoreFloat3(&pos, XMVector3Transform(XMLoadFloat3(&pos), XMLoadFloat4x4(&Matrix)));
		f3World = pos;
	}
	if (fYaw != 0.0f)
	{
		/*f3Rotated.x = float(f3World.x * cos(fYaw) + f3World.z * sin(fYaw));
		f3Rotated.z = float(-f3World.x * sin(fYaw) + f3World.z * cos(fYaw));
		f3World.x = f3Rotated.x;
		f3World.z = f3Rotated.z;*/
		XMFLOAT3 pos = f3Rotated.ToXMFLOAT3();
		XMFLOAT4X4 Matrix;
		Matrix._11 = cos(fYaw); Matrix._12 = 0.0f; Matrix._13 = -sin(fYaw), Matrix._14 = 0.0f;
		Matrix._21 = 0.0f; Matrix._22 = 1.0f; Matrix._23 = 0.0; Matrix._24 = 0.0f;
		Matrix._31 = sin(fYaw); Matrix._32 = 0.0; Matrix._33 = cos(fYaw); Matrix._34 = 0.0f;
		Matrix._41 = 0.0f; Matrix._42 = 0.0f; Matrix._43 = 0.0f; Matrix._44 = 1.0f;

		XMStoreFloat3(&pos, XMVector3Transform(XMLoadFloat3(&pos), XMLoadFloat4x4(&Matrix)));
		f3World = pos;
	}
	if (fRoll != 0.0f)
	{
		/*f3Rotated.x = float(f3World.x * cos(fRoll) - f3World.y * sin(fRoll));
		f3Rotated.y = float(f3World.x * sin(fRoll) + f3World.y * cos(fRoll));
		f3World.x = f3Rotated.x;
		f3World.y = f3Rotated.y;*/
		XMFLOAT3 pos = f3Rotated.ToXMFLOAT3();
		XMFLOAT4X4 Matrix;
		Matrix._11 = cos(fRoll); Matrix._12 = sin(fRoll); Matrix._13 = 0.0f, Matrix._14 = 0.0f;
		Matrix._21 = -sin(fRoll); Matrix._22 = cos(fRoll); Matrix._23 = 0.0f; Matrix._24 = 0.0f;
		Matrix._31 = 0.0f; Matrix._32 = 0.0f; Matrix._33 = 1.0f; Matrix._34 = 0.0f;
		Matrix._41 = 0.0f; Matrix._42 = 0.0f; Matrix._43 = 0.0f; Matrix._44 = 1.0f;

		XMStoreFloat3(&pos, XMVector3Transform(XMLoadFloat3(&pos), XMLoadFloat4x4(&Matrix)));
		f3World = pos;
	}
	XMFLOAT3 pos = f3World.ToXMFLOAT3();
	XMStoreFloat3(&pos, XMVector3Transform(XMLoadFloat3(&pos), XMMatrixTranslation(m_fPosition.x, m_fPosition.y, m_fPosition.z)));
	
	f3World = pos;

	return(f3World);
}

void CGameObject::Animate(float fElapsedTime)
{
	Rotate(m_fRotationSpeed.x * fElapsedTime, m_fRotationSpeed.y * fElapsedTime, m_fRotationSpeed.z * fElapsedTime);
}

void CGameObject::Render(HDC hDCFrameBuffer)
{
	HPEN hPen = ::CreatePen(PS_SOLID, 0, m_dwColor);
	HPEN hOldPen = (HPEN)::SelectObject(hDCFrameBuffer, hPen);

	if (m_pMesh) m_pMesh->Render(hDCFrameBuffer);

	::SelectObject(hDCFrameBuffer, hOldPen);
	::DeleteObject(hPen);
}
