//------------------------------------------------------- ----------------------
// File: Object.h
//-----------------------------------------------------------------------------

#pragma once

#include "Mesh.h"
#include "Camera.h"

class CShader;

class CGameObject
{
protected:
	bool isActive;
	XMFLOAT3 m_dir;
	float m_fMovingSpeed = 0.1f;
public:
	CGameObject();
	virtual ~CGameObject();

public:
	XMFLOAT4X4						m_xmf4x4World;
	CMesh* m_pMesh = NULL;

	CShader* m_pShader = NULL;

	XMFLOAT3						m_xmf3Color = XMFLOAT3(1.0f, 1.0f, 1.0f);

	void SetMesh(CMesh* pMesh);
	void SetShader(CShader* pShader);

	virtual void CreateShaderVariables(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	virtual void UpdateShaderVariables(ID3D12GraphicsCommandList* pd3dCommandList);
	virtual void ReleaseShaderVariables();

	virtual void Animate(float fTimeElapsed);
	virtual void OnPrepareRender() { }
	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera = NULL);

	virtual void ReleaseUploadBuffers();

	XMFLOAT3 GetPosition();
	XMFLOAT3 GetLook();
	XMFLOAT3 GetUp();
	XMFLOAT3 GetRight();

	void SetPosition(float x, float y, float z);
	void SetPosition(XMFLOAT3 xmf3Position);

	void SetColor(XMFLOAT3 xmf3Color) { m_xmf3Color = xmf3Color; }

	void MoveStrafe(float fDistance = 1.0f);
	void MoveUp(float fDistance = 1.0f);
	void MoveForward(float fDistance = 1.0f);

	void Rotate(float fPitch = 10.0f, float fYaw = 10.0f, float fRoll = 10.0f);
	void Rotate(XMFLOAT3* pxmf3Axis, float fAngle);
	void SetMovingDirection(XMFLOAT3& direction);
	void SetMovingSpeed(float fSpeed) { m_fMovingSpeed = fSpeed; }
	bool GetIsActive();
	void SetIsActive(bool active);

};

class CUfoObject : public CGameObject //¿Ã∞Õ¿Ã ∆¯∆»«“ ∞Õ¿Ã¥Ÿ.
{
	CGameObject** explorObjects{ nullptr }; //∆¯πﬂ∆ƒ∆º≈¨
	const int m_explosionCount = 100;
	XMFLOAT3 startPos;
	XMFLOAT3 m_dir;
public:
	CUfoObject(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	virtual ~CUfoObject();
	XMFLOAT3 GetMovieReverseDir();
	void SetParticlePosition();

	virtual void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera = NULL);
	virtual void Animate(float fElapsedTime);
};

class CMap :public CGameObject //∏ ¿Ã¥Ÿ.
{
public:
	CMap(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	virtual ~CMap();
};
class CBullet :public CGameObject
{

	bool isLockon;
public:
	XMFLOAT3 dir = XMFLOAT3(0, 0, 0);
	CBullet();

	virtual void Move(XMFLOAT3& vDirection, float fSpeed);
	virtual void Animate(float fElapsedTime);

	virtual ~CBullet();
};