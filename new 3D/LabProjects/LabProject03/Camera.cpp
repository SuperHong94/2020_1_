#include "stdafx.h"
#include "Camera.h"
//#include "Mesh.h"
#include "Player.h" //8���� �߰�����

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//CCamera::CCamera()
//{
//	//m_fPosition = XMFLOAT3(0.0f, 0.0f, 0.0f);
//	//m_fRotation = XMFLOAT3(0.0f, 0.0f, 0.0f);
//
//	///*view._11 = 1.0f; view._12 = 0.0f; view._13 = 0.0f, view._14 = 0.0f;
//	//view._21 = 0.0f; view._22 = 1.0f; view._23 = 0.0f; view._24 = 0.0f;
//	//view._31 = 0.0f; view._32 = 0.0f; view._33 = 1.0f; view._34 = 0.0f;
//	//view._41 = 0.0f; view._42 = 0.0f; view._43 = 0.0f; view._44 = 1.0f;*/
//}
//
//CCamera::~CCamera()
//{
//}


//8���� �º���Ʈ ����
//void CCamera::SetViewport(int nLeft, int nTop, int nWidth, int nHeight)
//{
//	m_pViewport = new CViewport(nLeft, nTop, nWidth, nHeight);
//	m_fAspectRatio = float(m_pViewport->m_nWidth) / float(m_pViewport->m_nHeight);
//}
void CViewport::SetViewport(int nLeft, int nTop, int nWidth, int
	nHeight)
{
	m_nLeft = nLeft;
	m_nTop = nTop;
	m_nWidth = nWidth;
	m_nHeight = nHeight;
}

//---
//8���� GenerateViewMatrix() �Լ��߰�
/*ī�޶� ���� �� ȸ���� �ϰ� �Ǹ� ������ �Ǽ� ǥ���� ���� ������ ī�޶��� ���� x-��(Right), y��(Up), z-��(Look)�� ���� �������� ���� �� �ִ�. ī�޶��� ���� x-��(Right), y-��(Up), z-��(Look)
�� ���� �����ϵ��� ������ش�.*/
void CCamera::GenerateViewMatrix()
{
	//ī�޶��� z-���� �������� ī�޶��� ��ǥ����� �����ϵ��� �����.
	XMVECTOR xmvLook = XMVector3Normalize(XMLoadFloat3(&m_xmf3Look));
	XMVECTOR xmvUp = XMVector3Normalize(XMLoadFloat3(&m_xmf3Up));
	XMVECTOR xmvRight = XMVector3Normalize(XMVector3Cross(xmvUp,
		xmvLook));
	xmvUp = XMVector3Normalize(XMVector3Cross(xmvLook, xmvRight));
	XMStoreFloat3(&m_xmf3Look, xmvLook);
	XMStoreFloat3(&m_xmf3Right, xmvRight);
	XMStoreFloat3(&m_xmf3Up, xmvUp);
	//ī�޶� ��ȯ ����� ī�޶� ���庯ȯ ����� �����(��ġ���)�̴�. 
	m_xmf4x4View._11 = m_xmf3Right.x; m_xmf4x4View._12 = m_xmf3Up.x;
	m_xmf4x4View._13 = m_xmf3Look.x;
	m_xmf4x4View._21 = m_xmf3Right.y; m_xmf4x4View._22 = m_xmf3Up.y;
	m_xmf4x4View._23 = m_xmf3Look.y;
	m_xmf4x4View._31 = m_xmf3Right.z; m_xmf4x4View._32 = m_xmf3Up.z;
	m_xmf4x4View._33 = m_xmf3Look.z;
	XMVECTOR xmvPosition = XMLoadFloat3(&m_xmf3Position);
	m_xmf4x4View._41 = -XMVectorGetX(XMVector3Dot(xmvPosition,
		xmvRight));
	m_xmf4x4View._42 = -XMVectorGetX(XMVector3Dot(xmvPosition, xmvUp));
	m_xmf4x4View._43 = -XMVectorGetX(XMVector3Dot(xmvPosition,
		xmvLook));
	XMStoreFloat4x4(&m_xmf4x4ViewProject,
		XMMatrixMultiply(XMLoadFloat4x4(&m_xmf4x4View),
			XMLoadFloat4x4(&m_xmf4x4Project)));
}
//----------------
//8���� SetLookAt()�Լ� �߰�
//ī�޶� xmf3LookAt�� �ٶ󺸵��� ī�޶� ��ȯ ����� �����Ѵ�. 
void CCamera::SetLookAt(XMFLOAT3& xmf3Position, XMFLOAT3& xmf3LookAt, XMFLOAT3& xmf3Up)
{
	m_xmf3Position = xmf3Position;
	XMStoreFloat4x4(&m_xmf4x4View,
		XMMatrixLookAtLH(XMLoadFloat3(&m_xmf3Position),
			XMLoadFloat3(&xmf3LookAt), XMLoadFloat3(&xmf3Up)));
	//ī�޶� ��ȯ ��Ŀ��� ī�޶��� x-��, y-��, z-���� ���Ѵ�. 
	XMVECTORF32 xmf32vRight = { m_xmf4x4View._11, m_xmf4x4View._21,
	m_xmf4x4View._31, 0.0f
	};
	XMVECTORF32 xmf32vUp = { m_xmf4x4View._12, m_xmf4x4View._22,
	m_xmf4x4View._32, 0.0f };
	XMVECTORF32 xmf32vLook = { m_xmf4x4View._13, m_xmf4x4View._23,
	m_xmf4x4View._33, 0.0f };
	XMStoreFloat3(&m_xmf3Right, XMVector3Normalize(xmf32vRight));
	XMStoreFloat3(&m_xmf3Up, XMVector3Normalize(xmf32vUp));
	XMStoreFloat3(&m_xmf3Look, XMVector3Normalize(xmf32vLook));
}
void CCamera::SetLookAt(XMFLOAT3& xmf3LookAt, XMFLOAT3& xmf3Up)
{
	//���� ī�޶��� ��ġ���� �÷��̾ �ٶ󺸱� ���� ī�޶� ��ȯ ����� �����Ѵ�.
	SetLookAt(m_xmf3Position, xmf3LookAt, xmf3Up);
}
//-------------------
//8����SetViewport() SetFOVAngle()
void CCamera::SetViewport(int nLeft, int nTop, int nWidth, int nHeight)
{
	m_Viewport.SetViewport(nLeft, nTop, nWidth, nHeight);
	m_fAspectRatio = float(m_Viewport.m_nWidth) /
		float(m_Viewport.m_nHeight);
}
void CCamera::SetFOVAngle(float fFOVAngle)
{
	m_fFOVAngle = fFOVAngle;
	m_fProjectRectDistance = float(1.0f /
		tan(XMConvertToRadians(fFOVAngle * 0.5f)));
}
//void CCamera::SetFOVAngle(float fFOVAngle)
//{
//	m_fFOVAngle = fFOVAngle;
//	m_fProjectRectDistance = float(1.0f / tan(DegreeToRadian(fFOVAngle * 0.5f)));
//}
//-----------------
//8���� GeneratePerspectiveProjectionMatrix() 
//���� ���� ��ȯ ����� �����Ѵ�
void CCamera::GeneratePerspectiveProjectionMatrix(float
	fNearPlaneDistance, float fFarPlaneDistance, float fFOVAngle)
{
	float fAspectRatio = (float(m_Viewport.m_nWidth) /
		float(m_Viewport.m_nHeight));
	XMStoreFloat4x4(&m_xmf4x4Project,
		XMMatrixPerspectiveFovLH(XMConvertToRadians(fFOVAngle), fAspectRatio,
			fNearPlaneDistance, fFarPlaneDistance));
}


//8���� Move ����
//void CCamera::Move(float x, float y, float z)
//{
//
//
//	//view = Matrix;
//	XMStoreFloat3(&m_fPosition, XMVector3Transform(XMLoadFloat3(&m_fPosition), XMMatrixTranslation(x, y, z)));
//	/*m_fPosition.x += x;
//	m_fPosition.y += y;
//	m_fPosition.z += z;*/
//}
void CCamera::Move(XMFLOAT3& xmf3Shift)
{
	XMStoreFloat3(&m_xmf3Position,
		XMVectorAdd(XMLoadFloat3(&m_xmf3Position), XMLoadFloat3(&xmf3Shift)));
}
void CCamera::Move(float x, float y, float z)
{
	Move(XMFLOAT3(x, y, z));
}


//8����Rotate����
//void CCamera::Rotate(float fPitch, float fYaw, float fRoll)
//{
//	XMStoreFloat3(&m_fRotation, XMVector3Transform(XMLoadFloat3(&m_fRotation), XMMatrixTranslation(fPitch, fYaw, fRoll)));
//	/*m_fRotation.x += fPitch;
//	m_fRotation.y += fYaw;
//	m_fRotation.z += fRoll;*/
//}
//
//CPoint3D CCamera::CameraTransform(CPoint3D& f3World)
//{
//	CPoint3D f3Camera = f3World;
//	f3Camera.x -= m_fPosition.x;
//	f3Camera.y -= m_fPosition.y;
//	f3Camera.z -= m_fPosition.z;
//
//	float fPitch = DegreeToRadian(-m_fRotation.x);
//	float fYaw = DegreeToRadian(-m_fRotation.y);
//	float fRoll = DegreeToRadian(-m_fRotation.z);
//
//	CPoint3D f3Rotated = f3Camera;
//
//	if (fPitch != 0.0f)
//	{
//		/*	f3Rotated.y = float(f3Camera.y * cos(fPitch) - f3Camera.z * sin(fPitch));
//			f3Rotated.z = float(f3Camera.y * sin(fPitch) + f3Camera.z * cos(fPitch));
//			f3Camera.y = f3Rotated.y;
//			f3Camera.z = f3Rotated.z;*/
//		XMFLOAT3 pos = f3Camera.ToXMFLOAT3();
//		XMFLOAT4X4 Matrix;
//		Matrix._11 = 1.0f; Matrix._12 = 0.0f; Matrix._13 = 0.0f, Matrix._14 = 0.0f;
//		Matrix._21 = 0.0f; Matrix._22 = cos(fPitch); Matrix._23 = sin(fPitch); Matrix._24 = 0.0f;
//		Matrix._31 = 0.0f; Matrix._32 = -sin(fPitch); Matrix._33 = cos(fPitch); Matrix._34 = 0.0f;
//		Matrix._41 = 0.0f; Matrix._42 = 0.0f; Matrix._43 = 0.0f; Matrix._44 = 1.0f;
//
//		//view = Matrix;
//		XMStoreFloat3(&pos, XMVector3Transform(XMLoadFloat3(&pos), XMLoadFloat4x4(&Matrix)));
//		f3Camera = pos;
//	}
//	if (fYaw != 0.0f)
//	{
//		/*f3Rotated.x = float(f3Camera.x * cos(fYaw) + f3Camera.z * sin(fYaw));
//		f3Rotated.z = float(-f3Camera.x * sin(fYaw) + f3Camera.z * cos(fYaw));
//		f3Camera.x = f3Rotated.x;
//		f3Camera.z = f3Rotated.z;*/
//		XMFLOAT3 pos = f3Camera.ToXMFLOAT3();
//		XMFLOAT4X4 Matrix;
//		Matrix._11 = cos(fYaw); Matrix._12 = 0.0f; Matrix._13 = -sin(fYaw), Matrix._14 = 0.0f;
//		Matrix._21 = 0.0f; Matrix._22 = 1.0f; Matrix._23 = 0.0; Matrix._24 = 0.0f;
//		Matrix._31 = sin(fYaw); Matrix._32 = 0.0; Matrix._33 = cos(fYaw); Matrix._34 = 0.0f;
//		Matrix._41 = 0.0f; Matrix._42 = 0.0f; Matrix._43 = 0.0f; Matrix._44 = 1.0f;
//		//view = Matrix;
//		XMStoreFloat3(&pos, XMVector3Transform(XMLoadFloat3(&pos), XMLoadFloat4x4(&Matrix)));
//		f3Camera = pos;
//	}
//	if (fRoll != 0.0f)
//	{
//		/*f3Rotated.x = float(f3Camera.x * cos(fRoll) - f3Camera.y * sin(fRoll));
//		f3Rotated.y = float(f3Camera.x * sin(fRoll) + f3Camera.y * cos(fRoll));
//		f3Camera.x = f3Rotated.x;
//		f3Camera.y = f3Rotated.y;*/
//		XMFLOAT3 pos = f3Camera.ToXMFLOAT3();
//		XMFLOAT4X4 Matrix;
//		Matrix._11 = cos(fRoll); Matrix._12 = sin(fRoll); Matrix._13 = 0.0f, Matrix._14 = 0.0f;
//		Matrix._21 = -sin(fRoll); Matrix._22 = cos(fRoll); Matrix._23 = 0.0f; Matrix._24 = 0.0f;
//		Matrix._31 = 0.0f; Matrix._32 = 0.0f; Matrix._33 = 1.0f; Matrix._34 = 0.0f;
//		Matrix._41 = 0.0f; Matrix._42 = 0.0f; Matrix._43 = 0.0f; Matrix._44 = 1.0f;
//		//view = Matrix;
//		XMStoreFloat3(&pos, XMVector3Transform(XMLoadFloat3(&pos), XMLoadFloat4x4(&Matrix)));
//		f3Camera = pos;
//	}
//	/*XMFLOAT3 pos = f3Camera.ToXMFLOAT3();
//	XMFLOAT3 right = XMFLOAT3(f3Camera.x, 0.0f, 0.0f);
//	XMFLOAT3 up = XMFLOAT3(0.0f, f3Camera.y, 0.0f);
//	XMFLOAT3 look = XMFLOAT3(0.0f, 0.0, f3Camera.z);
//	XMMATRIX m = XMMatrixLookAtLH(XMLoadFloat3(&right), XMLoadFloat3(&up), XMLoadFloat3(&look));
//	XMStoreFloat3(&pos, XMVector3Transform(XMLoadFloat3(&pos), m));*/
//	//f3Camera = pos;
//	return(f3Camera);
//}

void CCamera::Rotate(float fPitch, float fYaw, float fRoll)
{
	if (fPitch != 0.0f)
	{
		XMMATRIX xmmtxRotate =
			XMMatrixRotationAxis(XMLoadFloat3(&m_xmf3Right),
				XMConvertToRadians(fPitch));
		//ī�޶��� ���� x-��(Right)�� �߽����� ȸ���ϴ� ��ķ� y-��(Up), z-��(Look)�� ȸ���Ѵ�.
		XMStoreFloat3(&m_xmf3Look,
			XMVector3TransformNormal(XMLoadFloat3(&m_xmf3Look), xmmtxRotate));
		XMStoreFloat3(&m_xmf3Up,
			XMVector3TransformNormal(XMLoadFloat3(&m_xmf3Up), xmmtxRotate));
	}
	if (fYaw != 0.0f)
	{
		XMMATRIX xmmtxRotate =
			XMMatrixRotationAxis(XMLoadFloat3(&m_xmf3Up),
				XMConvertToRadians(fYaw));
		XMStoreFloat3(&m_xmf3Look,
			XMVector3TransformNormal(XMLoadFloat3(&m_xmf3Look), xmmtxRotate));
		XMStoreFloat3(&m_xmf3Right,
			XMVector3TransformNormal(XMLoadFloat3(&m_xmf3Right), xmmtxRotate));
	}
	if (fRoll != 0.0f)
	{
		XMMATRIX xmmtxRotate =
			XMMatrixRotationAxis(XMLoadFloat3(&m_xmf3Look),
				XMConvertToRadians(fRoll));
		XMStoreFloat3(&m_xmf3Up,
			XMVector3TransformNormal(XMLoadFloat3(&m_xmf3Up), xmmtxRotate));
		XMStoreFloat3(&m_xmf3Right,
			XMVector3TransformNormal(XMLoadFloat3(&m_xmf3Right), xmmtxRotate));
	}
	
}
//----------------
//8���� Update()�Լ� �߰�
void CCamera::Update(CPlayer* pPlayer, XMFLOAT3& xmf3LookAt, float
	fTimeElapsed)
{
	//�÷��̾��� ���� x-��, y-��, z-�� ���ͷκ��� ȸ�� ���(�÷��̾�� ���� ������ ��Ÿ���� ���)�������Ѵ�.
	XMMATRIX xmmtx4Rotate;
	xmmtx4Rotate.r[0] = XMVectorSet(pPlayer->m_xmf3Right.x,
		pPlayer->m_xmf3Right.y, pPlayer->m_xmf3Right.z, 0.0f);
	xmmtx4Rotate.r[1] = XMVectorSet(pPlayer->m_xmf3Up.x,
		pPlayer->m_xmf3Up.y, pPlayer->m_xmf3Up.z, 0.0f);
	xmmtx4Rotate.r[2] = XMVectorSet(pPlayer->m_xmf3Look.x,
		pPlayer->m_xmf3Look.y, pPlayer->m_xmf3Look.z, 0.0f);
	xmmtx4Rotate.r[3] = XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
	XMVECTOR xmvPosition = XMLoadFloat3(&m_xmf3Position);
	//ī�޶� ������ ���͸� ȸ�� ��ķ� ��ȯ(ȸ��)�Ѵ�.
	XMVECTOR xmvOffset =
		XMVector3TransformCoord(XMLoadFloat3(&pPlayer->m_xmf3CameraOffset),
			xmmtx4Rotate);
	//ȸ���� ī�޶��� ��ġ�� �÷��̾��� ��ġ�� ȸ���� ī�޶� ������ ���͸� ���� ���̴�.
	XMVECTOR xmvNewPosition =
		XMVectorAdd(XMLoadFloat3(&pPlayer->m_xmf3Position), xmvOffset);
	//������ ī�޶��� ��ġ���� ȸ���� ī�޶��� ��ġ������ ����� �Ÿ��� ��Ÿ���� �����̴�. 
	XMVECTOR xmvDirection = XMVectorSubtract(xmvNewPosition,
		xmvPosition);
	float fLength = XMVectorGetX(XMVector3Length(xmvDirection));
	xmvDirection = XMVector3Normalize(xmvDirection);
	/*ī�޶��� ����(Lag)�� �÷��̾ ȸ���ϴ��� ī�޶� ���ÿ� ���� ȸ������ �ʰ� �ణ�� ������
�ΰ� ȸ���ϴ� ȿ���� �����ϱ� ���� ���̴�. ���� �׸����� �÷��̾ ȸ���� �� ī�޶�� c1���� c2
�� ������ �ΰ� õõ��(�����) �̵��ϸ鼭 �÷��̾ �ٶ󺸵��� �Ѵ�. 4.0�� 40.0���� �ٲپ� ȸ��
�� �غ��� ���̸� ���� �� ���� ���̴�.*/
	float fTimeLagScale = fTimeElapsed * 4.0f;
	float fDistance = fLength * fTimeLagScale;
	if (fDistance > fLength) fDistance = fLength;
	if (fLength < 0.01f) fDistance = fLength;
	if (fDistance > 0)
	{
		//ī�޶� �������� �ʰ� �̵��� �Ѵ�(ȸ���� ������ ���� ��� ȸ�� �̵��� ���� �̵��� ���� ����).
		XMStoreFloat3(&m_xmf3Position, XMVectorAdd(xmvPosition,
			XMVectorScale(xmvDirection, fDistance)));
		//ī�޶� �÷��̾ �ٶ󺸵��� �Ѵ�. 
		SetLookAt(pPlayer->m_xmf3Position, pPlayer->m_xmf3Up);
	}
}


//8���� ������ �Լ�
//CPoint3D CCamera::ProjectionTransform(CPoint3D& f3Camera)
//{
//	CPoint3D f3Project = f3Camera;
//	if (f3Camera.z != 0.0f)
//	{
//
//		/*f3Project.x = float((f3Camera.x * m_fProjectRectDistance) / (m_fAspectRatio * f3Camera.z));
//		f3Project.y = float((f3Camera.y * m_fProjectRectDistance) / f3Camera.z);
//		f3Project.z = f3Camera.z;*/
//		XMFLOAT3 pos = f3Project.ToXMFLOAT3();
//		XMFLOAT4X4 Matrix;
//		Matrix._11 = m_fProjectRectDistance * (1 / m_fAspectRatio); Matrix._12 = 0.0f; Matrix._13 = 0.0f, Matrix._14 = 0.0f;
//		Matrix._21 = 0.0f; Matrix._22 = m_fProjectRectDistance; Matrix._23 = 0.0f; Matrix._24 = 0.0f;
//		Matrix._31 = 0.0f; Matrix._32 = 0.0f; Matrix._33 = zf / (zf - zn); Matrix._34 = 1.0f;
//		Matrix._41 = 0.0f; Matrix._42 = 0.0f; Matrix._43 = (-zn * zf) / (zf - zn); Matrix._44 = 0.0f;
//
//
//		XMStoreFloat3(&pos, XMVector3TransformCoord(XMLoadFloat3(&pos), XMLoadFloat4x4(&Matrix)));
//
//		//XMMATRIX m = XMMatrixPerspectiveFovLH(m_pViewport->m_nWidth*0.5f, m_pViewport->m_nHeight*0.5f, zn, zf);
//		//XMStoreFloat3(&pos, XMVector3TransformCoord(XMLoadFloat3(&pos), m));
//		f3Project = pos;
//
//	}
//
//	return(f3Project);
//}
//
//CPoint3D CCamera::ScreenTransform(CPoint3D& f3Projection)
//{
//	CPoint3D f3Screen = f3Projection;
//
//	/*float fHalfWidth = m_pViewport->m_nWidth * 0.5f;
//	float fHalfHeight = m_pViewport->m_nHeight * 0.5f;
//	f3Screen.x = (f3Projection.x * fHalfWidth) + m_pViewport->m_nLeft + fHalfWidth;
//	f3Screen.y = (-f3Projection.y * fHalfHeight) + m_pViewport->m_nTop + fHalfHeight;*/
//
//	XMFLOAT3 pos = f3Screen.ToXMFLOAT3();
//	XMFLOAT4X4 Matrix;
//	Matrix._11 = m_pViewport->m_nWidth * 0.5f; Matrix._12 = 0.0f; Matrix._13 = 0.0f, Matrix._14 = 0.0f;
//	Matrix._21 = 0.0f; Matrix._22 = -(m_pViewport->m_nHeight * 0.5f); Matrix._23 = 0.0f; Matrix._24 = 0.0f;
//	Matrix._31 = 0.0f; Matrix._32 = 0.0f; Matrix._33 = 1.0f; Matrix._34 = 0.0f;
//	Matrix._41 = m_pViewport->m_nLeft + (m_pViewport->m_nWidth * 0.5f); Matrix._42 = m_pViewport->m_nTop + (m_pViewport->m_nHeight * 0.5f); Matrix._43 = (-zn * zf) / (zf - zn); Matrix._44 = 0.0f;
//	XMStoreFloat3(&pos, XMVector3Transform(XMLoadFloat3(&pos), XMLoadFloat4x4(&Matrix)));
//	f3Screen = pos;
//
//	return(f3Screen);
//}
