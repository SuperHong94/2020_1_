// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#define WIN32_LEAN_AND_MEAN		// 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>
#include <iostream>
#include <random>	
// C의 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <math.h>
//Direct X 헤더---
#include <DirectXMath.h> 
#include <DirectXPackedVector.h>
#include <DirectXColors.h> 
#include <DirectXCollision.h>
#include <Mmsystem.h>
//---
using namespace DirectX;
using namespace DirectX::PackedVector;
#pragma comment(lib, "winmm.lib")
//#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 콘솔창에서 찍어보기위해서 설정
#define FRAMEBUFFER_WIDTH		640
#define FRAMEBUFFER_HEIGHT		480

#define RANDOM_COLOR			(0xFF000000 | ((rand() * 0xFFFFFF) / RAND_MAX))

#define DegreeToRadian(x)		float((x)*3.141592654f/180.0f)

#define EPSILON					1.0e-2f

//8주차 추가내용----------
#define DIR_FORWARD 0x01
#define DIR_BACKWARD 0x02
#define DIR_LEFT 0x04
#define DIR_RIGHT 0x08
#define DIR_UP 0x10
#define DIR_DOWN 0x20


//WASD로도 이동가능하게 추가
#define VK_W  0x57
#define VK_S  0x53
#define VK_A  0x41
#define VK_D  0x44
#define VK_Z  0x5A
//MAP

#define MAPWIDTH 30.0f
#define MAPHEIGHT 30.0f
#define MAPDEPTH  10.0f

namespace Matrix4x4
{
	inline XMFLOAT4X4 Identity()
	{
		XMFLOAT4X4 xmmtx4x4Result;
		XMStoreFloat4x4(&xmmtx4x4Result, XMMatrixIdentity());
		return(xmmtx4x4Result);
	}
}
//------------

inline bool IsZero(float fValue) { return((fabsf(fValue) <= EPSILON)); }
inline bool IsEqual(float fA, float fB) { return(::IsZero(fA - fB)); }

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
