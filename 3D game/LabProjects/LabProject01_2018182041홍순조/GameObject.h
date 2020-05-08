#pragma once

#include "Mesh.h"

class CGameObject
{
public:
	CGameObject() { 
	}
	~CGameObject();

private:
	//게임 오브젝트 위치----
	XMFLOAT3 m_fPosition = XMFLOAT3(0.0f, 0.0f, 0.0f);
	/*float					m_fxPosition = 0.0f;
	float					m_fyPosition = 0.0f;
	float					m_fzPosition = 0.0f;*/
	//----

	//게임오브젝트 회전---
	XMFLOAT3 m_fRotation= XMFLOAT3(0.0f, 0.0f, 0.0f);
	//float					m_fxRotation = 0.0f;
	//float					m_fyRotation = 0.0f;
	//float					m_fzRotation = 0.0f;
	//-----------

    CMesh					*m_pMesh = NULL;        
	DWORD					m_dwColor = RGB(255, 0, 0);

	XMFLOAT3 m_fRotationSpeed= XMFLOAT3(0.0f, 0.0f, 0.0f);


public:
	void SetMesh(CMesh *pMesh) { m_pMesh = pMesh; if (pMesh) pMesh->AddRef(); }

	void SetColor(DWORD dwColor) { m_dwColor = dwColor; }

	void SetPosition(float x, float y, float z) { 
		XMVECTOR pos = XMVectorSet(x, y, z,1.0f);
		XMStoreFloat3(&m_fPosition,pos); }
	void SetRotation(float x, float y, float z) { XMStoreFloat3(&m_fRotation,XMVectorSet(x, y, z, 1.0f)); }
	void SetRotationSpeed(float x, float y, float z) { 
		XMStoreFloat3(&m_fRotationSpeed, XMVector3Transform(XMLoadFloat3(&m_fRotationSpeed), XMMatrixTranslation(x, y, z)));
	}

	void Move(float x, float y, float z) {
		XMStoreFloat3(&m_fPosition, XMVector3Transform(XMLoadFloat3(&m_fPosition), XMMatrixTranslation(x, y, z)));
		 }
	void Rotate(float x, float y, float z) {
		XMStoreFloat3(&m_fRotation, XMVector3Transform(XMLoadFloat3(&m_fRotation), XMMatrixTranslation(x, y, z)));

	}

public:
	CPoint3D WorldTransform(CPoint3D& f3Model);

	virtual void Animate(float fElapsedTime);
	virtual void Render(HDC hDCFrameBuffer);
};

