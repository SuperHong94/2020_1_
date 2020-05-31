#pragma once

#include "Mesh.h"


//8������ ����Ʈ Ŭ���� ����
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
//8���� ī�޶� ����
//class CCamera
//{
//public:
//	CCamera();
//	virtual ~CCamera();
//
//private:
//	//ī�޶� ��ġ------
//	XMFLOAT3 m_fPosition;
//	//float						m_fxPosition = 0.0f;
//	//float						m_fyPosition = 0.0f;
//	//float						m_fzPosition = 0.0f;
//	//-------
//	
//
//	//ī�޶� ȸ��----
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
//	//---zf, zn �߰�
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
	//ī�޶��� ��ġ(������ǥ��) �����̴�.
	XMFLOAT3 m_xmf3Position = XMFLOAT3(0.0f, 0.0f, 0.0f);
	//ī�޶��� ���� x-��(Right), y-��(Up), z-��(Look)�� ��Ÿ���� �����̴�.*/
	XMFLOAT3 m_xmf3Right = XMFLOAT3(1.0f, 0.0f, 0.0f);
	XMFLOAT3 m_xmf3Up = XMFLOAT3(0.0f, 1.0f, 0.0f);
	XMFLOAT3 m_xmf3Look = XMFLOAT3(0.0f, 0.0f, 1.0f);
	//ī�޶��� �þ߰�, ���� �簢�������� �Ÿ�
	float m_fFOVAngle = 90.0f;
	float m_fProjectRectDistance = 1.0f;
	//����Ʈ�� ���� ���̿� ���� ������ ����(��Ⱦ��: Aspect ratio)
	float m_fAspectRatio = float(FRAMEBUFFER_WIDTH) /
		float(FRAMEBUFFER_HEIGHT);
public:
	//ī�޶� ��ȯ ���
	XMFLOAT4X4 m_xmf4x4View = Matrix4x4::Identity();
	//���� ���� ��ȯ ���
	XMFLOAT4X4 m_xmf4x4Project = Matrix4x4::Identity();
	//ī�޶� ��ȯ ��� * ���� ���� ��ȯ ���
	XMFLOAT4X4 m_xmf4x4ViewProject = Matrix4x4::Identity();
	//����Ʈ
	CViewport m_Viewport;
public:
	void SetFOVAngle(float fFOVAngle);
	//ī�޶� ��ȯ ����� �����Ѵ�. 
	void GenerateViewMatrix();
	//���� ��ȯ ����� �����Ѵ�. 
	void GeneratePerspectiveProjectionMatrix(float fNearPlaneDistance,
		float fFarPlaneDistance, float fFOVAngle);
	void SetViewport(int nLeft, int nTop, int nWidth, int nHeight);
	//3��Ī ī�޶󿡼� ī�޶� �ٶ󺸴� ������ �����Ѵ�. �Ϲ������� �÷��̾ �ٶ󺸵��� �����Ѵ�. 
	void SetLookAt(XMFLOAT3& xmf3LookAt, XMFLOAT3& xmf3Up);
	void SetLookAt(XMFLOAT3& xmf3Position, XMFLOAT3& xmf3LookAt,
		XMFLOAT3& xmf3Up);
	//ī�޶� xmf3Shift ��ŭ �̵��Ѵ�.
	void Move(XMFLOAT3& xmf3Shift);
	void Move(float x, float y, float z);
	//ī�޶� x-��, y-��, z-������ ȸ���Ѵ�.
	void Rotate(float fPitch = 0.0f, float fYaw = 0.0f, float fRoll =
		0.0f);
	//ī�޶��� �̵�, ȸ���� ���� ī�޶��� ������ �����ϴ� �����Լ��̴�. 
	void Update(CPlayer* pPlayer, XMFLOAT3& xmf3LookAt, float
		fTimeElapsed = 0.016f);
};