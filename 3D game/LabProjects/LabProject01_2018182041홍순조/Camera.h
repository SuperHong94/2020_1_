#pragma once

#include "Mesh.h"


//8주차차 뷰포트 클래스 수정
//class CViewport
//{
//public:
//	CViewport(int nLeft, int nTop, int nWidth, int nHeight) { m_nLeft = nLeft; m_nTop = nTop; m_nWidth = nWidth; m_nHeight = nHeight; }
//	virtual ~CViewport() { }
//
//	int							m_nLeft;
//	int							m_nTop;
//	int							m_nWidth;
//	int							m_nHeight;
//};
class CViewport
{
public:
	CViewport() { }
	virtual ~CViewport() { }
	int m_nLeft;
	int m_nTop;
	int m_nWidth;
	int m_nHeight;
	void SetViewport(int nLeft, int nTop, int nWidth, int nHeight);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
//8주차 카메라 수정
//class CCamera
//{
//public:
//	CCamera();
//	virtual ~CCamera();
//
//private:
//	//카메라 위치------
//	XMFLOAT3 m_fPosition;
//	//float						m_fxPosition = 0.0f;
//	//float						m_fyPosition = 0.0f;
//	//float						m_fzPosition = 0.0f;
//	//-------
//	
//
//	//카메라 회전----
//	XMFLOAT3 m_fRotation;
//	//float						m_fxRotation = 0.0f;
//	//float						m_fyRotation = 0.0f;
//	//float						m_fzRotation = 0.0f;
//	//------
//	float						m_fFOVAngle = 90.0f;
//	float						m_fProjectRectDistance = 1.0f;
//
//	CViewport*					m_pViewport = NULL;
//	float						m_fAspectRatio = float(FRAMEBUFFER_WIDTH) / float(FRAMEBUFFER_HEIGHT);
//
//	//XMFLOAT4X4 view;
//	//---zf, zn 추가
//	float zn = + 0.0f;
//	float zf =  + 50.0f;
//	//------
//public:
//	CPoint3D CameraTransform(CPoint3D& f3World);
//	CPoint3D ProjectionTransform(CPoint3D& f3Camera);
//	CPoint3D ScreenTransform(CPoint3D& f3Projection);
//
//	void SetPosition(float x, float y, float z) {
//		XMVECTOR pos = XMVectorSet(x,y,z, 1.0f);
//		XMStoreFloat3(&m_fPosition,pos); }
//	void SetRotation(float fPitch, float fYaw, float fRoll) { m_fRotation = XMFLOAT3(fPitch, fYaw, fRoll); }
//
//	void SetViewport(int xStart, int yStart, int nWidth, int nHeight);
//	void SetFOVAngle(float fFOVAngle);
//	void Move(float x, float y, float z);
//	void Rotate(float fPitch, float fYaw, float fRoll);
//};

class CPlayer;
class CCamera
{
public:
	CCamera() { }
	virtual ~CCamera() { }
private:
	//카메라의 위치(월드좌표계) 벡터이다.
	XMFLOAT3 m_xmf3Position = XMFLOAT3(0.0f, 0.0f, 0.0f);
	//카메라의 로컬 x-축(Right), y-축(Up), z-축(Look)을 나타내는 벡터이다.*/
	XMFLOAT3 m_xmf3Right = XMFLOAT3(1.0f, 0.0f, 0.0f);
	XMFLOAT3 m_xmf3Up = XMFLOAT3(0.0f, 1.0f, 0.0f);
	XMFLOAT3 m_xmf3Look = XMFLOAT3(0.0f, 0.0f, 1.0f);
	//카메라의 시야각, 투영 사각형까지의 거리
	float m_fFOVAngle = 90.0f;
	float m_fProjectRectDistance = 1.0f;
	//뷰포트의 가로 길이와 세로 길이의 비율(종횡비: Aspect ratio)
	float m_fAspectRatio = float(FRAMEBUFFER_WIDTH) /
		float(FRAMEBUFFER_HEIGHT);
public:
	//카메라 변환 행렬
	XMFLOAT4X4 m_xmf4x4View = Matrix4x4::Identity();
	//원근 투영 변환 행렬
	XMFLOAT4X4 m_xmf4x4Project = Matrix4x4::Identity();
	//카메라 변환 행렬 * 원근 투영 변환 행렬
	XMFLOAT4X4 m_xmf4x4ViewProject = Matrix4x4::Identity();
	//뷰포트
	CViewport m_Viewport;
public:
	void SetFOVAngle(float fFOVAngle);
	//카메라 변환 행렬을 생성한다. 
	void GenerateViewMatrix();
	//투영 변환 행렬을 생성한다. 
	void GeneratePerspectiveProjectionMatrix(float fNearPlaneDistance,
		float fFarPlaneDistance, float fFOVAngle);
	void SetViewport(int nLeft, int nTop, int nWidth, int nHeight);
	//3인칭 카메라에서 카메라가 바라보는 지점을 설정한다. 일반적으로 플레이어를 바라보도록 설정한다. 
	void SetLookAt(XMFLOAT3& xmf3LookAt, XMFLOAT3& xmf3Up);
	void SetLookAt(XMFLOAT3& xmf3Position, XMFLOAT3& xmf3LookAt,
		XMFLOAT3& xmf3Up);
	//카메라를 xmf3Shift 만큼 이동한다.
	void Move(XMFLOAT3& xmf3Shift);
	void Move(float x, float y, float z);
	//카메라를 x-축, y-축, z-축으로 회전한다.
	void Rotate(float fPitch = 0.0f, float fYaw = 0.0f, float fRoll =
		0.0f);
	//카메라의 이동, 회전에 따라 카메라의 정보를 갱신하는 가상함수이다. 
	void Update(CPlayer* pPlayer, XMFLOAT3& xmf3LookAt, float
		fTimeElapsed = 0.016f);
};