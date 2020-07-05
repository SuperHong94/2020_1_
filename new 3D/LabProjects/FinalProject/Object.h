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

	bool IsVisible(CCamera* pCamera = NULL);

	//모델 좌표계의 픽킹 광선을 생성한다.
	void GenerateRayForPicking(XMFLOAT3& xmf3PickPosition, XMFLOAT4X4& xmf4x4View, XMFLOAT3* pxmf3PickRayOrigin, XMFLOAT3* pxmf3PickRayDirection);
	//카메라 좌표계의 한 점에 대한 모델 좌표계의 픽킹 광선을 생성하고 객체와의 교차를 검사한다.
	int PickObjectByRayIntersection(XMFLOAT3& xmf3PickPosition, XMFLOAT4X4& xmf4x4View, float* pfHitDistance);

};

class CUfoObject : public CGameObject //이것이 폭팔할 것이다.
{
	CGameObject** explorObjects{ nullptr }; //폭발파티클
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

class CMap :public CGameObject //맵이다.
{
public:
	CMap(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	virtual ~CMap();
};



class CBullet :public CGameObject
{

	bool isLockon;
	XMFLOAT3 startPos;
public:
	XMFLOAT3 dir = XMFLOAT3(0, 0, 0);
	CBullet();
	void SetStartPos(XMFLOAT3& pos);
	virtual void Move(XMFLOAT3& vDirection, float fSpeed);
	virtual void Animate(float fElapsedTime);

	virtual ~CBullet();
};