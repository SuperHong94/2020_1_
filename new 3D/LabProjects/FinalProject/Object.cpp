//-----------------------------------------------------------------------------
// File: CGameObject.cpp
//-----------------------------------------------------------------------------

#include "stdafx.h"
#include "Object.h"
#include "Shader.h"

CGameObject::CGameObject()
{
	m_xmf4x4World = Matrix4x4::Identity();
}

CGameObject::~CGameObject()
{
	if (m_pMesh) m_pMesh->Release();
	if (m_pShader) m_pShader->Release();
}

void CGameObject::SetMesh(CMesh* pMesh)
{
	if (m_pMesh) m_pMesh->Release();
	m_pMesh = pMesh;
	if (m_pMesh) m_pMesh->AddRef();
}

void CGameObject::SetShader(CShader* pShader)
{
	if (m_pShader) m_pShader->Release();
	m_pShader = pShader;
	if (m_pShader) m_pShader->AddRef();
}

void CGameObject::Animate(float fTimeElapsed)
{
	SetPosition(m_xmf4x4World._41 + m_dir.x * m_fMovingSpeed,
		m_xmf4x4World._42 + m_dir.y * m_fMovingSpeed, m_xmf4x4World._43 +
		m_dir.z * m_fMovingSpeed);
}



void CGameObject::CreateShaderVariables(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
}

void CGameObject::UpdateShaderVariables(ID3D12GraphicsCommandList* pd3dCommandList)
{
	XMFLOAT4X4 xmf4x4World;
	XMStoreFloat4x4(&xmf4x4World, XMMatrixTranspose(XMLoadFloat4x4(&m_xmf4x4World)));
	pd3dCommandList->SetGraphicsRoot32BitConstants(1, 16, &xmf4x4World, 0);

	pd3dCommandList->SetGraphicsRoot32BitConstants(1, 3, &m_xmf3Color, 16);
}

void CGameObject::ReleaseShaderVariables()
{
}

void CGameObject::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	OnPrepareRender();

	if (m_pShader) m_pShader->Render(pd3dCommandList, pCamera);

	UpdateShaderVariables(pd3dCommandList);

	if (m_pMesh) m_pMesh->Render(pd3dCommandList);
}

void CGameObject::ReleaseUploadBuffers()
{
	if (m_pMesh) m_pMesh->ReleaseUploadBuffers();
}

void CGameObject::SetPosition(float x, float y, float z)
{
	m_xmf4x4World._41 = x;
	m_xmf4x4World._42 = y;
	m_xmf4x4World._43 = z;
}

void CGameObject::SetPosition(XMFLOAT3 xmf3Position)
{
	SetPosition(xmf3Position.x, xmf3Position.y, xmf3Position.z);
}



XMFLOAT3 CGameObject::GetPosition()
{
	return(XMFLOAT3(m_xmf4x4World._41, m_xmf4x4World._42, m_xmf4x4World._43));
}

XMFLOAT3 CGameObject::GetLook()
{
	return(Vector3::Normalize(XMFLOAT3(m_xmf4x4World._31, m_xmf4x4World._32, m_xmf4x4World._33)));
}

XMFLOAT3 CGameObject::GetUp()
{
	return(Vector3::Normalize(XMFLOAT3(m_xmf4x4World._21, m_xmf4x4World._22, m_xmf4x4World._23)));
}

XMFLOAT3 CGameObject::GetRight()
{
	return(Vector3::Normalize(XMFLOAT3(m_xmf4x4World._11, m_xmf4x4World._12, m_xmf4x4World._13)));
}

void CGameObject::MoveStrafe(float fDistance)
{
	XMFLOAT3 xmf3Position = GetPosition();
	XMFLOAT3 xmf3Right = GetRight();
	xmf3Position = Vector3::Add(xmf3Position, xmf3Right, fDistance);
	CGameObject::SetPosition(xmf3Position);
}

void CGameObject::MoveUp(float fDistance)
{
	XMFLOAT3 xmf3Position = GetPosition();
	XMFLOAT3 xmf3Up = GetUp();
	xmf3Position = Vector3::Add(xmf3Position, xmf3Up, fDistance);
	CGameObject::SetPosition(xmf3Position);
}

void CGameObject::MoveForward(float fDistance)
{
	XMFLOAT3 xmf3Position = GetPosition();
	XMFLOAT3 xmf3Look = GetLook();
	xmf3Position = Vector3::Add(xmf3Position, xmf3Look, fDistance);
	CGameObject::SetPosition(xmf3Position);
}

void CGameObject::Rotate(float fPitch, float fYaw, float fRoll)
{
	XMMATRIX mtxRotate = XMMatrixRotationRollPitchYaw(XMConvertToRadians(fPitch), XMConvertToRadians(fYaw), XMConvertToRadians(fRoll));
	m_xmf4x4World = Matrix4x4::Multiply(mtxRotate, m_xmf4x4World);
}

void CGameObject::Rotate(XMFLOAT3* pxmf3Axis, float fAngle)
{
	XMMATRIX mtxRotate = XMMatrixRotationAxis(XMLoadFloat3(pxmf3Axis), XMConvertToRadians(fAngle));
	m_xmf4x4World = Matrix4x4::Multiply(mtxRotate, m_xmf4x4World);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//맵만들기

CMap::CMap(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	CMapMesh* pCubeMesh = new CMapMesh(pd3dDevice, pd3dCommandList, 50.0f, 50.0f, 100.0f);
	SetMesh(pCubeMesh);
	SetPosition(0.0f, 0.0f, 0.0f);
	SetMovingSpeed(0.0f);
	SetColor(XMFLOAT3(0.0f, 0.0f, 0.0f));
	SetIsActive(true);
}
CMap::~CMap()
{

}

///
CUfoObject::CUfoObject(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	std::random_device rd;
	std::default_random_engine dre(rd());
	std::uniform_real_distribution uid(-10.0f, 10.0f);
	std::uniform_real_distribution ruid(0.0f, 1.0f);
	CMesh* pUfoMesh = new CMesh(pd3dDevice, pd3dCommandList, "Models/UFO.txt"); //적 오프젝트
	CCubeMeshDiffused* pCubeMesh = new CCubeMeshDiffused(pd3dDevice, pd3dCommandList, 1.0f, 1.0f, 1.0f);//폭발메쉬
	XMFLOAT3 pos = GetPosition();
	startPos = pos; //나중에 파티클 제거 할때 처음위치랑 비교
	explorObjects = new CGameObject * [m_explosionCount];

	XMFLOAT3 dir;
	for (int i = 0; i < m_explosionCount; ++i) {
		explorObjects[i] = new CGameObject;
		XMStoreFloat3(&dir, XMVector4Normalize(XMVectorSet(uid(dre), uid(dre), uid(dre), uid(dre))));
		explorObjects[i]->SetPosition(pos);
		explorObjects[i]->SetMesh(pCubeMesh);
		explorObjects[i]->SetColor(XMFLOAT3(1.0f, 1.0f, 0.0f));  //색깔 설정

		explorObjects[i]->SetMovingDirection(dir);
		explorObjects[i]->SetMovingSpeed(0.2f);
	}

	XMStoreFloat3(&m_dir, XMVector4Normalize(XMVectorSet(uid(dre), uid(dre), uid(dre), uid(dre)))); //기본 방향
	SetMesh(pUfoMesh);
	SetPosition(uid(dre), uid(dre), 50.f + uid(dre));
	OriginalColor = XMFLOAT3(ruid(dre), ruid(dre), ruid(dre));
	SetColor(OriginalColor);
	SetIsActive(true);
}

CUfoObject::~CUfoObject()
{

}


void CUfoObject::Animate(float fTimeElapsed) {
	if (isActive) {
		CGameObject::Animate(fTimeElapsed);
	}
	else {

		for (int i = 0; i < m_explosionCount; ++i)
			explorObjects[i]->Animate(fTimeElapsed);

		XMFLOAT3 dis;
		XMStoreFloat3(&dis, XMVector3Length(XMVectorSubtract(XMLoadFloat3(&startPos),
			XMLoadFloat3(&explorObjects[0]->GetPosition()))));
		if (dis.x > 30.0f) {
			SetColor(OriginalColor);
			isActive = true;
			//m_dwColor = OriginalColor;
		}
	}

}

void CUfoObject::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	if (isActive) {
		CGameObject::Render(pd3dCommandList, pCamera);
	}
	else {
		for (int i = 0; i < m_explosionCount; ++i) {
			explorObjects[i]->Render(pd3dCommandList, pCamera);
		}
	}
}



void CUfoObject::SetParticlePosition()
{
	XMFLOAT3 pos = GetPosition();
	startPos = pos;
	for (int i = 0; i < m_explosionCount; ++i)
	{

		explorObjects[i]->SetPosition(pos);
	}
}



//---------------총알
CBullet::CBullet()
{
	isActive = false; //초기에는 활성화 안됨
	isLockon = false;
}

CBullet::~CBullet()
{

}


void CBullet::Move(XMFLOAT3& vDirection, float fSpeed)
{
	SetPosition(m_xmf4x4World._41 + vDirection.x * fSpeed,
		m_xmf4x4World._42 + vDirection.y * fSpeed, m_xmf4x4World._43 +
		vDirection.z * fSpeed);
}


void CBullet::Animate(float fTimeElapsed) {
	if (isActive) {
		Move(dir, 100.0f * fTimeElapsed);
	}
	XMFLOAT3 dis;
	XMStoreFloat3(&dis, XMVector3Length(XMVectorSubtract(XMLoadFloat3(&startPos), XMLoadFloat3(&GetPosition()))));
	if (dis.x > 200.0f) {  //일정이상 멀어지면 비활성화
		isActive = false;
	}
	if (isLockon && dis.x > 20.0f) { //락온 상태이고 플레이어와 어느정도 떨어지면 유도미사일
		XMFLOAT3 targetPos = target->GetPosition();
		XMStoreFloat3(&dir, XMVector2Normalize(XMVectorSubtract(XMLoadFloat3(&targetPos),
			XMLoadFloat3(&GetPosition())))); //새로운 방향구하기
		SetMovingDirection(dir);

	}
}


bool CGameObject::GetIsActive()
{
	return isActive;
}
void CGameObject::SetIsActive(bool active)
{
	isActive = active;
}

void CGameObject::SetMovingDirection(XMFLOAT3& Direction) {
	XMStoreFloat3(&m_dir, XMVector3Normalize(XMLoadFloat3(&Direction)));
}