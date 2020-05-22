#pragma once

#include "Mesh.h"
#include "Camera.h" //8���� �߰�


//8���� CGameObject ����
class CGameObject
{
public:
	CGameObject() { }
	~CGameObject();
public:
	bool m_bActive = true;
	//���� ��ü�� ���(�޽�, ��)�̴�. 
	CMesh* m_pMesh = NULL;
	//���� ��ü�� ���� ��ȯ ����̴�. 
	XMFLOAT4X4 m_xmf4x4World = Matrix4x4::Identity();
	//���� ��ü�� ����(������ ����)�̴�.
	DWORD m_dwColor = RGB(255, 0, 0);
	//���� ��ü�� �̵� ������ ��Ÿ���� �����̴�. 
	XMFLOAT3 m_xmf3MovingDirection = XMFLOAT3(0.0f, 0.0f, 1.0f);
	float m_fMovingSpeed = 0.0f;
	float m_fMovingRange = 0.0f;
	//���� ��ü�� ȸ������ ��Ÿ���� �����̴�. 
	XMFLOAT3 m_xmf3RotationAxis = XMFLOAT3(0.0f, 1.0f, 0.0f);
	float m_fRotationSpeed = 0.0f;
public:
	void SetMesh(CMesh* pMesh) {
		m_pMesh = pMesh;
		if (pMesh)
			pMesh->AddRef();

	}
	void SetActive(bool bActive) { m_bActive = bActive; }
	void SetColor(DWORD dwColor) { m_dwColor = dwColor; }
	void SetPosition(float x, float y, float z);
	void SetPosition(XMFLOAT3& xmf3Position);
	void SetMovingDirection(XMFLOAT3& xmf3MovingDirection);
	void SetMovingSpeed(float fSpeed) { m_fMovingSpeed = fSpeed; }
	void SetMovingRange(float fRange) { m_fMovingRange = fRange; }
	void SetRotationAxis(XMFLOAT3& xmf3RotationAxis);
	void SetRotationSpeed(float fSpeed) { m_fRotationSpeed = fSpeed; }
	virtual void Move(XMFLOAT3& vDirection, float fSpeed);
	void Rotate(float fPitch, float fYaw, float fRoll);
	void Rotate(XMFLOAT3& xmf3Axis, float fAngle);
	virtual void OnUpdateTransform() { }
	virtual void Animate(float fElapsedTime);
	virtual void Render(HDC hDCFrameBuffer, CCamera* pCamera);

	XMFLOAT3& GetPosition() const;
};

class CBullet :public CGameObject
{
	XMFLOAT3 startPos;
	XMFLOAT3 nowPos;

public:
	CBullet(const XMFLOAT3&);
	XMFLOAT3& GetStartPos();

	virtual void Move(XMFLOAT3& vDirection, float fSpeed);
	virtual ~CBullet();

};

class CMap :public CGameObject
{
	float widht, depth, height;
public:
	CMap() {

	}
	virtual ~CMap() {

	}
};