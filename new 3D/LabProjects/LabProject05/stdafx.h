// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <string>
#include <wrl.h>	
#include <shellapi.h>

#include <d3d12.h>
#include <dxgi1_4.h>
#include <d3Dcompiler.h>

#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <DirectXColors.h>

#include <DirectXCollision.h>
#include <dxgidebug.h>

#include <mmsystem.h>//시간
#include <iostream>
using namespace DirectX;
using namespace DirectX::PackedVector;

using Microsoft::WRL::ComPtr;


//임포트 라이브러리 추가

#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib") //시간
//#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") //콘솔창에서 찍어보기위해서 설정
//윈도우 크기 설정
#define FRAME_BUFFER_WIDTH 800
#define FRAME_BUFFER_HEIGHT 600
//#define _WITH_SWAPCHAIN_FULLSCREEN_STATE //설정하면 처음부터 전체화면