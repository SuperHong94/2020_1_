#pragma once
#include "Timer.h"
#include "Scene.h"
#include "Camera.h"
#include "Player.h"
class CGameFramework
{
private:
	HINSTANCE m_hInstance;
	HWND m_hWnd;
	int m_nWndClientWidth;
	int m_nWndClientHeight;

	//DXGI ���丮 �������̽��� ���� �������̴�. 
	IDXGIFactory4* m_pdxgiFactory;

	//���� ü�� �������̽��� ���� �������̴�. �ַ� ���÷��̸� �����ϱ� ���Ͽ� �ʿ��ϴ�. 
	IDXGISwapChain3* m_pdxgiSwapChain;

	//Direct3D ����̽� �������̽��� ���� �������̴�. �ַ� ���ҽ��� �����ϱ� ���Ͽ� �ʿ��ϴ�.
	ID3D12Device* m_pd3dDevice;

	bool m_bMsaa4xEnable = false;
	UINT m_nMsaa4xQualityLevels = 0;
	//MSAA ���� ���ø��� Ȱ��ȭ�ϰ� ���� ���ø� ������ �����Ѵ�. 

	static const UINT m_nSwapChainBuffers = 2;
	//���� ü���� �ĸ� ������ �����̴�.

	UINT m_nSwapChainBufferIndex;
	//���� ���� ü���� �ĸ� ���� �ε����̴�. 

	ID3D12Resource* m_ppd3dRenderTargetBuffers[m_nSwapChainBuffers];
	ID3D12DescriptorHeap* m_pd3dRtvDescriptorHeap;
	UINT m_nRtvDescriptorIncrementSize;
	//���� Ÿ�� ����, ������ �� �������̽� ������, ���� Ÿ�� ������ ������ ũ���̴�.

	ID3D12Resource* m_pd3dDepthStencilBuffer;
	ID3D12DescriptorHeap* m_pd3dDsvDescriptorHeap;
	UINT m_nDsvDescriptorIncrementSize;
	//����-���ٽ� ����, ������ �� �������̽� ������, ����-���ٽ� ������ ������ ũ���̴�.

	ID3D12CommandQueue* m_pd3dCommandQueue;
	ID3D12CommandAllocator* m_pd3dCommandAllocator;
	ID3D12GraphicsCommandList* m_pd3dCommandList;
	//���� ť, ���� �Ҵ���, ���� ����Ʈ �������̽� �������̴�. 

	ID3D12PipelineState* m_pd3dPipelineState;
	//�׷��Ƚ� ���������� ���� ��ü�� ���� �������̽� �������̴�. 


	// �ĸ���۸��� ������ �潺 ���� �����ϱ� ���Ͽ� m_nFenceValue ��� ������ ������ ���� �����Ѵ�. 
	ID3D12Fence* m_pd3dFence;
	UINT64 m_nFenceValues[m_nSwapChainBuffers];
	HANDLE m_hFenceEvent;
	//�潺 �������̽� ������, �潺�� ��, �̺�Ʈ �ڵ��̴�. 

	D3D12_VIEWPORT m_d3dViewport;
	D3D12_RECT m_d3dScissorRect;
	//����Ʈ�� ���� �簢���̴�.

	//������ ���� �����ӿ�ũ���� ����� Ÿ�̸��̴�.
	CGameTimer m_GameTimer;
	//������ ������ ����Ʈ�� �� �������� ĸ�ǿ� ����ϱ� ���� ���ڿ��̴�.
	_TCHAR m_pszFrameRate[50];


	CScene* m_pScene;


public:
	CGameFramework();
	~CGameFramework();

	//�÷��̾� ��ü�� ���� �������̴�.
	CPlayer* m_pPlayer = NULL;

	//���콺 ��ư�� Ŭ���� ���� ���콺 Ŀ���� ��ġ�̴�. 
	POINT m_ptOldCursorPos; 

	CCamera* m_pCamera = NULL;
	bool OnCreate(HINSTANCE hInstance, HWND hMainWnd);
	//�����ӿ�ũ�� �ʱ�ȭ�ϴ� �Լ��̴�(�� �����찡 �����Ǹ� ȣ��ȴ�).

	void OnDestroy();
	void CreateSwapChain();
	void CreateRtvAndDsvDescriptorHeaps();
	void CreateDirect3DDevice();
	void CreateCommandQueueAndList();
	//���� ü��, ����̽�, ������ ��, ���� ť/�Ҵ���/����Ʈ�� �����ϴ� �Լ��̴�.

	void CreateRenderTargetViews();
	void CreateDepthStencilView();
	//���� Ÿ�� ��� ����-���ٽ� �並 �����ϴ� �Լ��̴�. 

	void BuildObjects();
	void ReleaseObjects();
	//�������� �޽��� ���� ��ü�� �����ϰ� �Ҹ��ϴ� �Լ��̴�.

	//�����ӿ�ũ�� �ٽ�(����� �Է�, �ִϸ��̼�, ������)�� �����ϴ� �Լ��̴�.
	void ProcessInput();
	void AnimateObjects();
	void FrameAdvance();

	void WaitForGpuComplete();
	//CPU�� GPU�� ����ȭ�ϴ� �Լ��̴�. 

	void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK OnProcessingWindowMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	//�������� �޽���(Ű����, ���콺 �Է�)�� ó���ϴ� �Լ��̴�. 

	void ChangeSwapChainState();

	void MoveToNextFrame();
};
