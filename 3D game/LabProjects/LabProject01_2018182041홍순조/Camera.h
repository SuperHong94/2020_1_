#pragma once

#include "Mesh.h"

class CViewport
{
public:
	CViewport(int nLeft, int nTop, int nWidth, int nHeight) { m_nLeft = nLeft; m_nTop = nTop; m_nWidth = nWidth; m_nHeight = nHeight; }
	virtual ~CViewport() { }

	int							m_nLeft;
	int							m_nTop;
	int							m_nWidth;
	int							m_nHeight;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
class CCamera
{
public:
	CCamera();
	virtual ~CCamera();

private:
	//ī�޶� ��ġ------
	XMFLOAT3 m_fPosition;
	//float						m_fxPosition = 0.0f;
	//float						m_fyPosition = 0.0f;
	//float						m_fzPosition = 0.0f;
	//-------
	

	//ī�޶� ȸ��----
	XMFLOAT3 m_fRotation;
	//float						m_fxRotation = 0.0f;
	//float						m_fyRotation = 0.0f;
	//float						m_fzRotation = 0.0f;
	//------
	float						m_fFOVAngle = 90.0f;
	float						m_fProjectRectDistance = 1.0f;

	CViewport*					m_pViewport = NULL;
	float						m_fAspectRatio = float(FRAMEBUFFER_WIDTH) / float(FRAMEBUFFER_HEIGHT);

	//XMFLOAT4X4 view;
	//---zf, zn �߰�
	float zn = + 0.0f;
	float zf =  + 50.0f;
	//------
public:
	CPoint3D CameraTransform(CPoint3D& f3World);
	CPoint3D ProjectionTransform(CPoint3D& f3Camera);
	CPoint3D ScreenTransform(CPoint3D& f3Projection);

	void SetPosition(float x, float y, float z) {
		XMVECTOR pos = XMVectorSet(x,y,z, 1.0f);
		XMStoreFloat3(&m_fPosition,pos); }
	void SetRotation(float fPitch, float fYaw, float fRoll) { m_fRotation = XMFLOAT3(fPitch, fYaw, fRoll); }

	void SetViewport(int xStart, int yStart, int nWidth, int nHeight);
	void SetFOVAngle(float fFOVAngle);
	void Move(float x, float y, float z);
	void Rotate(float fPitch, float fYaw, float fRoll);
};
