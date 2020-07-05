//-----------------------------------------------------------------------------
// File: Scene.h
//-----------------------------------------------------------------------------

#pragma once

#include "Shader.h"
#include "Player.h"

class CScene
{
public:
	CScene();
	~CScene();

	bool OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	bool OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);

	void BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	void ReleaseObjects();

	ID3D12RootSignature* CreateGraphicsRootSignature(ID3D12Device* pd3dDevice);
	ID3D12RootSignature* GetGraphicsRootSignature() { return(m_pd3dGraphicsRootSignature); }

	bool ProcessInput();
	void AnimateObjects(float fTimeElapsed);
	void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera = NULL);

	void ReleaseUploadBuffers();


	bool IsPickingObject(int x, int y, CCamera* pCamera); //��ŷ�Լ�
	bool IsCollision();//�浹 üũ�Լ�
	bool IsCollision(XMFLOAT3); //��ŷ �˻�
	void SetPlayer(CPlayer* pPlayer);
	void AllFire();

protected:
	ID3D12RootSignature* m_pd3dGraphicsRootSignature = NULL;

	//��ġ(Batch) ó���� �ϱ� ���Ͽ� ���� ���̴����� ����Ʈ�� ǥ���Ѵ�. 
	CObjectsShader* m_pShaders = NULL;
	CMapShader* m_pMap;
	int m_nShaders = 0;

	CPlayer* m_pPlayer = NULL;
};
