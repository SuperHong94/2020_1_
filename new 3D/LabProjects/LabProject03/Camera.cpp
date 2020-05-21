#include "stdafx.h"
#include "Camera.h"
//#include "Mesh.h"
#include "Player.h" //8주차 추가사항

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


//8주차 셋뷰포트 수정
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
//8주차 GenerateViewMatrix() 함수추가
/*카메라가 여러 번 회전을 하게 되면 누적된 실수 표현의 문제 때문에 카메라의 로컬 x-축(Right), y축(Up), z-축(Look)이 서로 직교하지 않을 수 있다. 카메라의 로컬 x-축(Right), y-축(Up), z-축(Look)
이 서로 직교하도록 만들어준다.*/
void CCamera::GenerateViewMatrix()
{
	//카메라의 z-축을 기준으로 카메라의 좌표축들이 직교하도록 만든다.
	XMVECTOR xmvLook = XMVector3Normalize(XMLoadFloat3(&m_xmf3Look));
	XMVECTOR xmvUp = XMVector3Normalize(XMLoadFloat3(&m_xmf3Up));
	XMVECTOR xmvRight = XMVector3Normalize(XMVector3Cross(xmvUp,
		xmvLook));
	xmvUp = XMVector3Normalize(XMVector3Cross(xmvLook, xmvRight));
	XMStoreFloat3(&m_xmf3Look, xmvLook);
	XMStoreFloat3(&m_xmf3Right, xmvRight);
	XMStoreFloat3(&m_xmf3Up, xmvUp);
	//카메라 변환 행렬은 카메라 월드변환 행렬의 역행렬(전치행렬)이다. 
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
//8주차 SetLookAt()함수 추가
//카메라가 xmf3LookAt을 바라보도록 카메라 변환 행렬을 갱신한다. 
void CCamera::SetLookAt(XMFLOAT3& xmf3Position, XMFLOAT3& xmf3LookAt, XMFLOAT3& xmf3Up)
{
	m_xmf3Position = xmf3Position;
	XMStoreFloat4x4(&m_xmf4x4View,
		XMMatrixLookAtLH(XMLoadFloat3(&m_xmf3Position),
			XMLoadFloat3(&xmf3LookAt), XMLoadFloat3(&xmf3Up)));
	//카메라 변환 행렬에서 카메라의 x-축, y-축, z-축을 구한다. 
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
	//현재 카메라의 위치에서 플레이어를 바라보기 위한 카메라 변환 행렬을 생성한다.
	SetLookAt(m_xmf3Position, xmf3LookAt, xmf3Up);
}
//-------------------
//8주차SetViewport() SetFOVAngle()
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
//8주차 GeneratePerspectiveProjectionMatrix() 
//원근 투영 변환 행렬을 생성한다
void CCamera::GeneratePerspectiveProjectionMatrix(float
	fNearPlaneDistance, float fFarPlaneDistance, float fFOVAngle)
{
	float fAspectRatio = (float(m_Viewport.m_nWidth) /
		float(m_Viewport.m_nHeight));
	XMStoreFloat4x4(&m_xmf4x4Project,
		XMMatrixPerspectiveFovLH(XMConvertToRadians(fFOVAngle), fAspectRatio,
			fNearPlaneDistance, fFarPlaneDistance));
}


//8주차 Move 수정
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


//8주차Rotate수정
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
		//카메라의 로컬 x-축(Right)을 중심으로 회전하는 행렬로 y-축(Up), z-축(Look)을 회전한다.
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
//8주차 Update()함수 추가
void CCamera::Update(CPlayer* pPlayer, XMFLOAT3& xmf3LookAt, float
	fTimeElapsed)
{
	//플레이어의 로컬 x-축, y-축, z-축 벡터로부터 회전 행렬(플레이어와 같은 방향을 나타내는 행렬)을생성한다.
	XMMATRIX xmmtx4Rotate;
	xmmtx4Rotate.r[0] = XMVectorSet(pPlayer->m_xmf3Right.x,
		pPlayer->m_xmf3Right.y, pPlayer->m_xmf3Right.z, 0.0f);
	xmmtx4Rotate.r[1] = XMVectorSet(pPlayer->m_xmf3Up.x,
		pPlayer->m_xmf3Up.y, pPlayer->m_xmf3Up.z, 0.0f);
	xmmtx4Rotate.r[2] = XMVectorSet(pPlayer->m_xmf3Look.x,
		pPlayer->m_xmf3Look.y, pPlayer->m_xmf3Look.z, 0.0f);
	xmmtx4Rotate.r[3] = XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
	XMVECTOR xmvPosition = XMLoadFloat3(&m_xmf3Position);
	//카메라 오프셋 벡터를 회전 행렬로 변환(회전)한다.
	XMVECTOR xmvOffset =
		XMVector3TransformCoord(XMLoadFloat3(&pPlayer->m_xmf3CameraOffset),
			xmmtx4Rotate);
	//회전한 카메라의 위치는 플레이어의 위치에 회전한 카메라 오프셋 벡터를 더한 것이다.
	XMVECTOR xmvNewPosition =
		XMVectorAdd(XMLoadFloat3(&pPlayer->m_xmf3Position), xmvOffset);
	//현재의 카메라의 위치에서 회전한 카메라의 위치까지의 방향과 거리를 나타내는 벡터이다. 
	XMVECTOR xmvDirection = XMVectorSubtract(xmvNewPosition,
		xmvPosition);
	float fLength = XMVectorGetX(XMVector3Length(xmvDirection));
	xmvDirection = XMVector3Normalize(xmvDirection);
	/*카메라의 래그(Lag)는 플레이어가 회전하더라도 카메라가 동시에 따라서 회전하지 않고 약간의 시차를
두고 회전하는 효과를 구현하기 위한 것이다. 다음 그림에서 플레이어가 회전할 때 카메라는 c1에서 c2
로 시차를 두고 천천히(나누어서) 이동하면서 플레이어를 바라보도록 한다. 4.0을 40.0으로 바꾸어 회전
을 해보면 차이를 느낄 수 있을 것이다.*/
	float fTimeLagScale = fTimeElapsed * 4.0f;
	float fDistance = fLength * fTimeLagScale;
	if (fDistance > fLength) fDistance = fLength;
	if (fLength < 0.01f) fDistance = fLength;
	if (fDistance > 0)
	{
		//카메라를 공전하지 않고 이동을 한다(회전의 각도가 작은 경우 회전 이동은 선형 이동과 거의 같다).
		XMStoreFloat3(&m_xmf3Position, XMVectorAdd(xmvPosition,
			XMVectorScale(xmvDirection, fDistance)));
		//카메라가 플레이어를 바라보도록 한다. 
		SetLookAt(pPlayer->m_xmf3Position, pPlayer->m_xmf3Up);
	}
}


//8주차 삭제된 함수
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
