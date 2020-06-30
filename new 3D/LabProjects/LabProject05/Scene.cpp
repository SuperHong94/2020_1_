#include "stdafx.h"
#include "Scene.h"
CScene::CScene()
{
	m_pd3dPipelineState = NULL;
	m_pd3dGraphicsRootSignature = NULL;
}

CScene::~CScene()
{
}

void CScene::BuildObjects(ID3D12Device* pd3dDevice)
{
	//루트시그너쳐 생성-> 최종적으로 파이프라인스테이트 생성
	//루트 시그너쳐를 생성한다.
	D3D12_ROOT_SIGNATURE_DESC d3dRootSignatureDesc;
	::ZeroMemory(&d3dRootSignatureDesc, sizeof(D3D12_ROOT_SIGNATURE_DESC));
	d3dRootSignatureDesc.NumParameters = 0; //루트 시그니쳐의 슬롯(파라메터)개수
	d3dRootSignatureDesc.pParameters = NULL;
	d3dRootSignatureDesc.NumStaticSamplers = 0; //정적샘플러의 개수(2032개)
	d3dRootSignatureDesc.pStaticSamplers = NULL;
	d3dRootSignatureDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT; //루트 시그너쳐 레이아웃을 위한 선택 사항

	ID3DBlob* pd3dSignatureBlob = NULL;
	ID3DBlob* pd3dErrorBlob = NULL;

	::D3D12SerializeRootSignature(&d3dRootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &pd3dSignatureBlob, &pd3dErrorBlob);
	/*D3D12SerializeRootSignature() 함수에서 생성된 ID3DBlob이 있다면 루트 시그너쳐를 생성하고 난 다음에 Release()를 하는 겁니다.
	D3D12SerializeRootSignature() 함수 호출이 성공하면 pd3dSignatureBlob이 NULL이 아닐 것이고(pd3dSignatureBlob는 직렬화된 루트 시그너쳐에대한 포인터이다.)
	함수 호출이 실패하면 pd3dErrorBlob이 NULL이 아닐 겁니다.
	*/

	pd3dDevice->CreateRootSignature(0, pd3dSignatureBlob->GetBufferPointer(), pd3dSignatureBlob->GetBufferSize(),
		__uuidof(ID3D12RootSignature), (void**)&m_pd3dGraphicsRootSignature); //첫번째 인자는 노드마스크 우리는 단일GPU니깐 0이다.


	if (pd3dSignatureBlob) pd3dSignatureBlob->Release();

	if (pd3dErrorBlob) pd3dErrorBlob->Release();

	//정점 셰이더와 픽셀 셰이더를 생성한다. 
	ID3DBlob* pd3dVertexShaderBlob = NULL;
	ID3DBlob* pd3dPixelShaderBlob = NULL;
	UINT nCompileFlags = 0; // 옵션 없이

#if defined(_DEBUG)
	nCompileFlags = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;  //디버그버전
#endif
	//정점쉐이더를 컴파일한다. 
	D3DCompileFromFile(L"Shaders.hlsl", NULL, NULL, "VSMain", "vs_5_1", nCompileFlags, 0, &pd3dVertexShaderBlob, NULL);
	/*
	쉐이더 소스 이름, 쉐이더메크로 정의, ID3DInclude pinclude,쉐이더함수이름, 쉐이더 모델(특성레벨), 쉐이더 컴파일선택택사항, 이펙트컴파일 선택사항, 성공하면 블럭만들어주고, 에러나면 블럭)
	*/
	//픽셀쉐이더
	D3DCompileFromFile(L"Shaders.hlsl", NULL, NULL, "PSMain", "ps_5_1", nCompileFlags, 0, &pd3dPixelShaderBlob, NULL);


	//래스터라이저 상태를 설정한다.
	D3D12_RASTERIZER_DESC d3dRasterizerDesc;
	::ZeroMemory(&d3dRasterizerDesc, sizeof(D3D12_RASTERIZER_DESC));
	d3dRasterizerDesc.FillMode = D3D12_FILL_MODE_SOLID; //채우기 모드설정 지금설정은 다각형의 면을 그리는 설정
	d3dRasterizerDesc.CullMode = D3D12_CULL_MODE_BACK; //그리지 않을 면 방향 BACK은 후면 컬링
	d3dRasterizerDesc.FrontCounterClockwise = FALSE; //전면이 반시계방향(FALSE)
	d3dRasterizerDesc.DepthBias = 0; //픽셀의 깊이값(z)에 더해질 깊이 바이어스 값(0)
	d3dRasterizerDesc.DepthBiasClamp = 0.0f; //픽셀의 깊이값에 더해질 최대값(0.0)
	d3dRasterizerDesc.SlopeScaledDepthBias = 0.0f; //픽셀의 기울기 따라 바이어스를 조절할 값(0.0) DepthBias~SlopeScaledDepthBias는 그림자 그릴 때 사용
	d3dRasterizerDesc.DepthClipEnable = TRUE;  //깊이값을 사용한 클리핑
	d3dRasterizerDesc.MultisampleEnable = FALSE; //더중샘플링
	d3dRasterizerDesc.AntialiasedLineEnable = FALSE; //안티에얼리어싱
	d3dRasterizerDesc.ForcedSampleCount = 0; //UAV렌더링에 사영할 샘플리의 개수
	d3dRasterizerDesc.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;  //보수적레스터라이션 사용OFF(사용하면 픽셀계산 많아짐)

	//블렌드 상태를 설정한다. OM에서 주로하는거
	D3D12_BLEND_DESC d3dBlendDesc;
	::ZeroMemory(&d3dBlendDesc, sizeof(D3D12_BLEND_DESC));
	d3dBlendDesc.AlphaToCoverageEnable = FALSE;
	d3dBlendDesc.IndependentBlendEnable = FALSE;
	d3dBlendDesc.RenderTarget[0].BlendEnable = FALSE;
	d3dBlendDesc.RenderTarget[0].LogicOpEnable = FALSE;
	d3dBlendDesc.RenderTarget[0].SrcBlend = D3D12_BLEND_ONE;
	d3dBlendDesc.RenderTarget[0].DestBlend = D3D12_BLEND_ZERO;
	d3dBlendDesc.RenderTarget[0].BlendOp = D3D12_BLEND_OP_ADD;
	d3dBlendDesc.RenderTarget[0].SrcBlendAlpha = D3D12_BLEND_ONE;
	d3dBlendDesc.RenderTarget[0].DestBlendAlpha = D3D12_BLEND_ZERO;
	d3dBlendDesc.RenderTarget[0].BlendOpAlpha = D3D12_BLEND_OP_ADD;
	d3dBlendDesc.RenderTarget[0].LogicOp = D3D12_LOGIC_OP_NOOP;
	d3dBlendDesc.RenderTarget[0].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
	//그래픽 파이프라인 상태를 설정한다. 
	D3D12_GRAPHICS_PIPELINE_STATE_DESC d3dPipelineStateDesc;
	::ZeroMemory(&d3dPipelineStateDesc, sizeof(D3D12_GRAPHICS_PIPELINE_STATE_DESC));
	d3dPipelineStateDesc.pRootSignature = m_pd3dGraphicsRootSignature;
	d3dPipelineStateDesc.VS.pShaderBytecode = pd3dVertexShaderBlob->GetBufferPointer();
	d3dPipelineStateDesc.VS.BytecodeLength = pd3dVertexShaderBlob->GetBufferSize();
	d3dPipelineStateDesc.PS.pShaderBytecode = pd3dPixelShaderBlob->GetBufferPointer();
	d3dPipelineStateDesc.PS.BytecodeLength = pd3dPixelShaderBlob->GetBufferSize();
	d3dPipelineStateDesc.RasterizerState = d3dRasterizerDesc;
	d3dPipelineStateDesc.BlendState = d3dBlendDesc;
	d3dPipelineStateDesc.DepthStencilState.DepthEnable = FALSE;
	d3dPipelineStateDesc.DepthStencilState.StencilEnable = FALSE;
	d3dPipelineStateDesc.InputLayout.pInputElementDescs = NULL; //입력조립기 설정 
	d3dPipelineStateDesc.InputLayout.NumElements = 0;
	d3dPipelineStateDesc.SampleMask = UINT_MAX;
	d3dPipelineStateDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE; ///삼각형
	d3dPipelineStateDesc.NumRenderTargets = 1;
	d3dPipelineStateDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
	d3dPipelineStateDesc.DSVFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;
	d3dPipelineStateDesc.SampleDesc.Count = 1;
	d3dPipelineStateDesc.SampleDesc.Quality = 0;
	pd3dDevice->CreateGraphicsPipelineState(&d3dPipelineStateDesc, __uuidof(ID3D12PipelineState), (void**)&m_pd3dPipelineState);
	if (pd3dVertexShaderBlob) pd3dVertexShaderBlob->Release();
	if (pd3dPixelShaderBlob) pd3dPixelShaderBlob->Release();
}

void CScene::ReleaseObjects()
{
	if (m_pd3dGraphicsRootSignature) m_pd3dGraphicsRootSignature->Release();
	if (m_pd3dPipelineState) m_pd3dPipelineState->Release();
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

void CScene::AnimateObjects(float fTimeElapsed)
{
}

void CScene::Render(ID3D12GraphicsCommandList* pd3dCommandList)
{
	//그래픽 루트 시그너쳐를 설정한다.
	pd3dCommandList->SetGraphicsRootSignature(m_pd3dGraphicsRootSignature);
	//파이프라인 상태를 설정한다. 
	pd3dCommandList->SetPipelineState(m_pd3dPipelineState);
	//프리미티브 토폴로지(삼각형 리스트)를 설정한다. 
	pd3dCommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	//정점 3개를 사용하여 렌더링한다. 
	pd3dCommandList->DrawInstanced(3, 1, 0, 0);  //렌더링할 정점의 개수, 인스턴스의 개수(인스턴스 데이터가 없으면 1), 시작 정점의 위치, 인스턴스 인덱스에 더해지는 값
}