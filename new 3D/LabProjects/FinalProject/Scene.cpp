//-----------------------------------------------------------------------------
// File: CScene.cpp
//-----------------------------------------------------------------------------

#include "stdafx.h"
#include "Scene.h"

CScene::CScene()
{

}

CScene::~CScene()
{
}

void CScene::BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList)
{
	m_pd3dGraphicsRootSignature = CreateGraphicsRootSignature(pd3dDevice);

	m_nShaders = 1;
	m_pShaders = new CObjectsShader[m_nShaders];
	m_pShaders[0].CreateShader(pd3dDevice, m_pd3dGraphicsRootSignature);
	m_pShaders[0].BuildObjects(pd3dDevice, pd3dCommandList);

	m_pMap = new CMapShader();
	m_pMap->CreateShader(pd3dDevice, m_pd3dGraphicsRootSignature);
	m_pMap->BuildObjects(pd3dDevice, pd3dCommandList);

}

ID3D12RootSignature* CScene::CreateGraphicsRootSignature(ID3D12Device* pd3dDevice)
{
	ID3D12RootSignature* pd3dGraphicsRootSignature = NULL;

	D3D12_ROOT_PARAMETER pd3dRootParameters[3];
	pd3dRootParameters[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS;
	pd3dRootParameters[0].Constants.Num32BitValues = 4; //Time, ElapsedTime, xCursor, yCursor
	pd3dRootParameters[0].Constants.ShaderRegister = 0; //Time
	pd3dRootParameters[0].Constants.RegisterSpace = 0;
	pd3dRootParameters[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

	pd3dRootParameters[1].ParameterType = D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS;
	pd3dRootParameters[1].Constants.Num32BitValues = 19; //16 + 3
	pd3dRootParameters[1].Constants.ShaderRegister = 1; //World
	pd3dRootParameters[1].Constants.RegisterSpace = 0;
	pd3dRootParameters[1].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

	pd3dRootParameters[2].ParameterType = D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS;
	pd3dRootParameters[2].Constants.Num32BitValues = 35; //16 + 16 + 3
	pd3dRootParameters[2].Constants.ShaderRegister = 2; //Camera
	pd3dRootParameters[2].Constants.RegisterSpace = 0;
	pd3dRootParameters[2].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

	D3D12_ROOT_SIGNATURE_FLAGS d3dRootSignatureFlags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
	D3D12_ROOT_SIGNATURE_DESC d3dRootSignatureDesc;
	::ZeroMemory(&d3dRootSignatureDesc, sizeof(D3D12_ROOT_SIGNATURE_DESC));
	d3dRootSignatureDesc.NumParameters = _countof(pd3dRootParameters);
	d3dRootSignatureDesc.pParameters = pd3dRootParameters;
	d3dRootSignatureDesc.NumStaticSamplers = 0;
	d3dRootSignatureDesc.pStaticSamplers = NULL;
	d3dRootSignatureDesc.Flags = d3dRootSignatureFlags;

	ID3DBlob* pd3dSignatureBlob = NULL;
	ID3DBlob* pd3dErrorBlob = NULL;
	D3D12SerializeRootSignature(&d3dRootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &pd3dSignatureBlob, &pd3dErrorBlob);
	pd3dDevice->CreateRootSignature(0, pd3dSignatureBlob->GetBufferPointer(), pd3dSignatureBlob->GetBufferSize(), __uuidof(ID3D12RootSignature), (void**)&pd3dGraphicsRootSignature);
	if (pd3dSignatureBlob) pd3dSignatureBlob->Release();
	if (pd3dErrorBlob) pd3dErrorBlob->Release();

	return(pd3dGraphicsRootSignature);
}

void CScene::ReleaseObjects()
{
	if (m_pd3dGraphicsRootSignature) m_pd3dGraphicsRootSignature->Release();
	for (int i = 0; i < m_nShaders; i++)
	{
		m_pShaders[i].ReleaseShaderVariables();
		m_pShaders[i].ReleaseObjects();
	}
	if (m_pShaders) delete[] m_pShaders;
}

void CScene::ReleaseUploadBuffers()
{
	m_pMap->ReleaseUploadBuffers();
	for (int i = 0; i < m_nShaders; i++)
		m_pShaders[i].ReleaseUploadBuffers();

}
void CScene::AnimateObjects(float fTimeElapsed)
{
	float halfWidth = MAPWIDTH * 0.5f;
	float halfHeight = MAPHEIGHT * 0.5f;
	IsCollision();

	for (int i = 0; i < m_nShaders; i++)
	{
		m_pShaders[i].AnimateObjects(fTimeElapsed);
	}


	XMFLOAT3 pos = m_pPlayer->GetPosition();

	if (pos.x <= -halfWidth || pos.y >= halfHeight || pos.x >= halfWidth || pos.y <= -halfHeight ||
		pos.z >= MAPDEPTH*0.2f || pos.z <= -MAPDEPTH * 0.2f) {
		m_pPlayer->SetPosition(XMFLOAT3(0.0f, 0.0f, 0.0f));
		m_pPlayer->ChangeCamera(THIRD_PERSON_CAMERA, 0.0f);
	}

}

bool CScene::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	return(false);
}

bool CScene::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	return(false);
}

bool CScene::ProcessInput()
{
	return(false);
}


void CScene::Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera)
{
	pCamera->SetViewportsAndScissorRects(pd3dCommandList);
	pd3dCommandList->SetGraphicsRootSignature(m_pd3dGraphicsRootSignature);
	pCamera->UpdateShaderVariables(pd3dCommandList);

	for (int j = 0; j < m_nShaders; j++)
	{
		m_pShaders[j].Render(pd3dCommandList, pCamera);
	}
	m_pMap->Render(pd3dCommandList, pCamera);
}



void CScene::SetPlayer(CPlayer* pPlayer)
{
	m_pPlayer = pPlayer;
}

bool CScene::IsCollision()
{
	bool IsContains = false;

	CUfoObject** ppObjects = m_pShaders[0].GetObjects();
	int nObjects = m_pShaders[0].GetObjectCnt();
	for (int iBullet = 0; iBullet < m_pPlayer->bulletCnt; ++iBullet) {
		if (m_pPlayer->bullets[iBullet].GetIsActive()) //활성화되어있는 총알이라면
		{
			CBullet* pBullet = &m_pPlayer->bullets[iBullet];
			BoundingOrientedBox xmbbModel = pBullet->m_pMesh->m_xmBoundingBox;
			xmbbModel.Transform(xmbbModel, XMLoadFloat4x4(&pBullet->m_xmf4x4World));
			for (int i = 0; i < nObjects; ++i) {
				BoundingOrientedBox other = ppObjects[i]->m_pMesh->m_xmBoundingBox;
				other.Transform(other, XMLoadFloat4x4(&ppObjects[i]->m_xmf4x4World));
				if (xmbbModel.Contains(other) != DirectX::DISJOINT) {
					ppObjects[i]->SetParticlePosition();
					ppObjects[i]->SetIsActive(false);

					pBullet->SetIsActive(false);
					IsContains = true;
				}
			}
		}
	}
	return IsContains;
}


bool CScene::IsCollision(XMFLOAT3 ray)
{
	bool IsContains = false;

	CUfoObject** ppObjects = m_pShaders[0].GetObjects();
	int nObjects = m_pShaders[0].GetObjectCnt();
	for (int i = 0; i < nObjects; ++i) {
		if (ppObjects[i]->GetIsActive()) {
			BoundingOrientedBox other = ppObjects[i]->m_pMesh->m_xmBoundingBox;
			other.Transform(other, XMLoadFloat4x4(&ppObjects[i]->m_xmf4x4World));
			other.Transform(other, XMLoadFloat4x4(&m_pPlayer->GetCamera()->GetViewMatrix()));
			if (other.Contains(XMLoadFloat3(&ray)) != DirectX::DISJOINT) {
				ppObjects[i]->SetColor(ppObjects[i]->GetMovieReverseDir());
				m_pPlayer->SetTarget(ppObjects[i]);

				IsContains = true;
				return IsContains;
			}
		}
	}
	return IsContains;
}

bool CScene::IsPickingObject(int x, int y, CCamera* pCamera)
{
	if (!pCamera) return(false);
	bool isPicking = false;
	XMFLOAT3 ralyDir = XMFLOAT3(0.0f, 0.0f, 0.0f); //광선방향



	
	XMFLOAT4X4 xmf4x4View = pCamera->GetViewMatrix();
	XMFLOAT4X4 xmf4x4Projection = pCamera->GetProjectionMatrix();
	D3D12_VIEWPORT d3dViewport = pCamera->GetViewport();
	XMFLOAT3 xmf3PickPosition;
	/*화면 좌표계의 점 (xClient, yClient)를 화면 좌표 변환의 역변환과 투영 변환의 역변환을 한다. 그 결과는 카메라
	좌표계의 점이다. 투영 평면이 카메라에서 z-축으로 거리가 1이므로 z-좌표는 1로 설정한다.*/
	xmf3PickPosition.x = (((2.0f * x) / d3dViewport.Width) - 1) / xmf4x4Projection._11;
	xmf3PickPosition.y = -(((2.0f * y) / d3dViewport.Height) - 1) / xmf4x4Projection._22;
	xmf3PickPosition.z = 1.0f;

	ralyDir = XMFLOAT3(xmf3PickPosition.x, xmf3PickPosition.y, xmf3PickPosition.z); //광선방향
	XMStoreFloat3(&ralyDir, XMVector2Normalize(XMLoadFloat3(&ralyDir)));
	XMFLOAT3 ray;
	float maxDis = 500.0f; //광선최대거리

	for (float i = maxDis; i > 0.0f; i -= 0.01f) {
		XMStoreFloat3(&ray, XMVectorScale(XMLoadFloat3(&ralyDir), i));
		//std::cout << ray.x << ' ' << ray.y << ' ' << ray.z << std::endl;
		isPicking = IsCollision(ray);
	}
	return isPicking;
}

void CScene::AllFire()
{
	m_pShaders[0].AllFire();
}