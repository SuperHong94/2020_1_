#pragma once

#include "Mesh.h"
#include "Camera.h" //8���� �߰�


//8���� CGameObject ����
class CGameObject
{
public:
	CGameObject() { }
	virtual ~CGameObject();
public:
	bool isBullet = false;
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

	//�Ⱥ��̱�
	bool IsVisible(CCamera* pCamera);

public:
	void SetMesh(CMesh* pMesh) {
		m_pMesh = pMesh;
		if (pMesh)
			pMesh->AddRef();

	}
	XMFLOAT4X4* GetWorldMatrix();
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

class CExplosion :public CGameObject
{
	CGameObject** explorObjects{ nullptr };
	XMFLOAT3 startPos;
	const int m_explosionCount = 100;
public:
	CExplosion();
	virtual ~CExplosion() {};

	void SetParticlePosition();
	virtual void Render(HDC hDCFrameBuffer, CCamera* pCamera);
	virtual void Animate(float fElapsedTime);
};



class CBullet :public CGameObject
{


public:

	CBullet(const XMFLOAT3&);

	virtual void Move(XMFLOAT3& vDirection, float fSpeed);
	virtual ~CBullet();

};

class CMap :public CGameObject
{
public:
	CMap() {

	}
	virtual ~CMap() {

	}
};