//-----------------------------------------------------------------------------
// File: CGameFramework.cpp
//-----------------------------------------------------------------------------

#include "stdafx.h"
#include "Player.h"
#include "Scene.h"
#include "GameFramework.h"
#include "GameObject.h"

//void CGameFramework::OnCreate(HINSTANCE hInstance, HWND hMainWnd)
//{
//	m_hInstance = hInstance;
//	m_hWnd = hMainWnd;
//
//	BuildFrameBuffer(); 
//
//	BuildObjects(); 
//
//	::srand(timeGetTime());
//}
//
//void CGameFramework::OnDestroy()
//{
//	ReleaseObjects();
//
//	if (m_hBitmapFrameBuffer) ::DeleteObject(m_hBitmapFrameBuffer);
//	if (m_hDCFrameBuffer) ::DeleteDC(m_hDCFrameBuffer);
//}
//

//
//void CGameFramework::BuildObjects()
//{
//	CCamera* pCamera = new CCamera();
//	pCamera->SetViewport(0, 0, FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT);
//	pCamera->SetFOVAngle(60.0f);
//
//	m_pPlayer = new CPlayer();
//	m_pPlayer->SetCamera(pCamera);
//
//	m_pPlayer->SetPosition(0.0f, 3.0f, -40.0f);
//
//	m_pScene = new CScene();
//	m_pScene->BuildObjects();
//}
//
//void CGameFramework::ReleaseObjects()
//{
//	if (m_pScene) m_pScene->ReleaseObjects();
//
//	if (m_pScene) delete m_pScene;
//
//	if (m_pPlayer) delete m_pPlayer;
//}
//
//void CGameFramework::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
//{
//	if (m_pScene) m_pScene->OnProcessingMouseMessage(hWnd, nMessageID, wParam, lParam);
//
//	switch (nMessageID)
//	{
//	case WM_LBUTTONDOWN:
//	case WM_RBUTTONDOWN:
//		::SetCapture(hWnd);
//		::GetCursorPos(&m_ptOldCursorPos);
//		break;
//	case WM_LBUTTONUP:
//	case WM_RBUTTONUP:
//		::ReleaseCapture();
//		break;
//	case WM_MOUSEMOVE:
//		break;
//	default:
//		break;
//	}
//}
//
//void CGameFramework::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
//{
//	if (m_pScene) m_pScene->OnProcessingKeyboardMessage(hWnd, nMessageID, wParam, lParam);
//
//	switch (nMessageID)
//	{
//	case WM_KEYDOWN:
//		switch (wParam)
//		{
//		case VK_ESCAPE:
//			::PostQuitMessage(0);
//			break;
//		case VK_RETURN:
//			break;
//		default:
//			break;
//		}
//		break;
//	default:
//		break;
//	}
//}
//
//LRESULT CALLBACK CGameFramework::OnProcessingWindowMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
//{
//	switch (nMessageID)
//	{
//	case WM_ACTIVATE:
//	{
//		if (LOWORD(wParam) == WA_INACTIVE)
//			m_GameTimer.Stop();
//		else
//			m_GameTimer.Start();
//		break;
//	}
//	case WM_SIZE:
//		break;
//	case WM_LBUTTONDOWN:
//	case WM_RBUTTONDOWN:
//	case WM_LBUTTONUP:
//	case WM_RBUTTONUP:
//	case WM_MOUSEMOVE:
//		OnProcessingMouseMessage(hWnd, nMessageID, wParam, lParam);
//		break;
//	case WM_KEYDOWN:
//	case WM_KEYUP:
//		OnProcessingKeyboardMessage(hWnd, nMessageID, wParam, lParam);
//		break;
//	}
//	return(0);
//}
//
//void CGameFramework::ProcessInput()
//{
//	static UCHAR pKeyBuffer[256];
//	if (::GetKeyboardState(pKeyBuffer))
//	{
//		float cxKeyDelta = 0.0f, cyKeyDelta = 0.0f, czKeyDelta = 0.0f;
//		if (pKeyBuffer[VK_UP] & 0xF0) czKeyDelta = +0.125f;
//		if (pKeyBuffer[VK_DOWN] & 0xF0) czKeyDelta = -0.125f;
//		if (pKeyBuffer[VK_LEFT] & 0xF0) cxKeyDelta = -0.125f;
//		if (pKeyBuffer[VK_RIGHT] & 0xF0) cxKeyDelta = +0.125f;
//		if (pKeyBuffer[VK_PRIOR] & 0xF0) cyKeyDelta = +0.125f;
//		if (pKeyBuffer[VK_NEXT] & 0xF0) cyKeyDelta = -0.125f;
//
//		if ((cxKeyDelta != 0.0f) || (cyKeyDelta != 0.0f) || (czKeyDelta != 0.0f)) m_pPlayer->Move(cxKeyDelta, cyKeyDelta, czKeyDelta);
//	}
//	if (GetCapture() == m_hWnd)
//	{
//		SetCursor(NULL);
//		POINT ptCursorPos;
//		GetCursorPos(&ptCursorPos);
//		float cxMouseDelta = (float)(ptCursorPos.x - m_ptOldCursorPos.x) / 3.0f;
//		float cyMouseDelta = (float)(ptCursorPos.y - m_ptOldCursorPos.y) / 3.0f;
//		SetCursorPos(m_ptOldCursorPos.x, m_ptOldCursorPos.y);
//		if (cxMouseDelta || cyMouseDelta)
//		{
//			if (pKeyBuffer[VK_RBUTTON] & 0xF0)
//				m_pPlayer->Rotate(cyMouseDelta, 0.0f, -cxMouseDelta);
//			else
//				m_pPlayer->Rotate(cyMouseDelta, cxMouseDelta, 0.0f);
//		}
//	}
//}
//
//void CGameFramework::AnimateObjects()
//{
//	float fTimeElapsed = m_GameTimer.GetTimeElapsed();
//	if (m_pScene) m_pScene->Animate(fTimeElapsed);
//}
//
//void CGameFramework::FrameAdvance()
//{    
//	m_GameTimer.Tick(60.0f);
//
//	ProcessInput();
//
//	AnimateObjects();
//
//    ClearFrameBuffer(RGB(90, 103, 224));
//
//	CCamera* pCamera = m_pPlayer->GetCamera();
//	if (m_pScene) m_pScene->Render(m_hDCFrameBuffer, pCamera);
//
//	PresentFrameBuffer();
//}
//
//


//8���� ����
void CGameFramework::OnCreate(HINSTANCE hInstance, HWND hMainWnd)
{
	::srand(timeGetTime());
	m_hInstance = hInstance;
	m_hWnd = hMainWnd;
	BuildFrameBuffer();
	BuildObjects();
	_tcscpy_s(m_pszFrameRate, _T("LabProject ("));
}
void CGameFramework::OnDestroy()
{
	ReleaseObjects();
	if (m_hBitmapFrameBuffer) ::DeleteObject(m_hBitmapFrameBuffer);
	if (m_hDCFrameBuffer) ::DeleteDC(m_hDCFrameBuffer);
}


void CGameFramework::BuildFrameBuffer() //������ ����
{
	::GetClientRect(m_hWnd, &m_rcClient);

	HDC hDC = ::GetDC(m_hWnd);

	m_hDCFrameBuffer = ::CreateCompatibleDC(hDC);
	m_hBitmapFrameBuffer = ::CreateCompatibleBitmap(hDC, m_rcClient.right - m_rcClient.left, m_rcClient.bottom - m_rcClient.top);
	::SelectObject(m_hDCFrameBuffer, m_hBitmapFrameBuffer);

	::ReleaseDC(m_hWnd, hDC);
	::SetBkMode(m_hDCFrameBuffer, TRANSPARENT);
}

void CGameFramework::ClearFrameBuffer(DWORD dwColor) //������ ����
{
	HPEN hPen = ::CreatePen(PS_SOLID, 0, dwColor);
	HPEN hOldPen = (HPEN)::SelectObject(m_hDCFrameBuffer, hPen);
	HBRUSH hBrush = ::CreateSolidBrush(dwColor);
	HBRUSH hOldBrush = (HBRUSH)::SelectObject(m_hDCFrameBuffer, hBrush);
	::Rectangle(m_hDCFrameBuffer, m_rcClient.left, m_rcClient.top, m_rcClient.right, m_rcClient.bottom);
	::SelectObject(m_hDCFrameBuffer, hOldBrush);
	::SelectObject(m_hDCFrameBuffer, hOldPen);
	::DeleteObject(hPen);
	::DeleteObject(hBrush);
}

void CGameFramework::PresentFrameBuffer() //������ ����
{
	HDC hDC = ::GetDC(m_hWnd);
	::BitBlt(hDC, m_rcClient.left, m_rcClient.top, m_rcClient.right - m_rcClient.left, m_rcClient.bottom - m_rcClient.top, m_hDCFrameBuffer, m_rcClient.left, m_rcClient.top, SRCCOPY);
	::ReleaseDC(m_hWnd, hDC);
}


void CGameFramework::BuildObjects()
{
	CCamera* pCamera = new CCamera();
	pCamera->SetViewport(0, 0, FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT);
	pCamera->GeneratePerspectiveProjectionMatrix(1.01f, 500.0f, 60.0f);
	pCamera->SetFOVAngle(60.0f);
	//����� �޽��� �����ϰ� �÷��̾� ��ü�� �����Ѵ�.
	CAirplaneMesh* pAirplaneMesh = new CAirplaneMesh(6.0f, 6.0f, 1.0f);
	m_pPlayer = new CAirplanePlayer();
	m_pPlayer->SetPosition(0.0f, 0.0f, 0.0f);
	m_pPlayer->SetMesh(pAirplaneMesh);
	m_pPlayer->SetColor(RGB(0, 0, 255));
	m_pPlayer->SetCamera(pCamera);
	//ī�޶�� �÷��̾� ��ü ���� ������ �÷��̾ �ٶ󺻴�.
	m_pPlayer->SetCameraOffset(XMFLOAT3(0.0f, 5.0f, -15.0f));
	m_pScene = new CScene(m_pPlayer);
	m_pScene->BuildObjects();
}
void CGameFramework::ReleaseObjects()
{
	//�� ��ü�� ���� ��ü���� �Ҹ��ϰ�, �� ��ü�� �÷��̾� ��ü�� �Ҹ��Ѵ�. 
	if (m_pScene) m_pScene->ReleaseObjects();
	if (m_pScene) delete m_pScene;
	if (m_pPlayer) delete m_pPlayer;
}



void CGameFramework::OnProcessingMouseMessage(HWND hWnd, UINT
	nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID)
	{
		//���콺 ĸ�ĸ� �ϰ� ���� ���콺 ��ġ�� �����´�. case WM_RBUTTONDOWN:
	case WM_LBUTTONDOWN:
		::SetCapture(hWnd);
		::GetCursorPos(&m_ptOldCursorPos);
		break;
		//���콺 ĸ�ĸ� �����Ѵ�. case WM_LBUTTONUP:
	case WM_RBUTTONUP:
		::ReleaseCapture();
		break;
	case WM_MOUSEMOVE:
		break;
	default:
		if (m_pScene) m_pScene->OnProcessingMouseMessage(hWnd,
			nMessageID, wParam, lParam);
		break;
	}
}


void CGameFramework::OnProcessingKeyboardMessage(HWND hWnd, UINT
	nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			::PostQuitMessage(0);
			break;
		case VK_RETURN:
			break;
		case VK_CONTROL:
			break;
		default:
			if (m_pScene) m_pScene->OnProcessingKeyboardMessage(hWnd,
				nMessageID, wParam, lParam);
			break;
		}
		break;
	default:
		break;
	}
}

LRESULT CALLBACK CGameFramework::OnProcessingWindowMessage(HWND hWnd,
	UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID)
	{
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MOUSEMOVE:
		OnProcessingMouseMessage(hWnd, nMessageID, wParam, lParam);
		break;
	case WM_KEYDOWN:
	case WM_KEYUP:
		OnProcessingKeyboardMessage(hWnd, nMessageID, wParam, lParam);
		break;
	}
	return(0);
}


void CGameFramework::ProcessInput()
{

	static UCHAR pKeyBuffer[256];
	/*Ű������ ���� ������ ��ȯ�Ѵ�. ȭ��ǥ Ű(���桯, ���硯, ���衯, ���顯)�� ������ �÷��̾ ������/����(��
	�� x-��), ��/��(���� z-��)�� �̵��Ѵ�. ��Page Up���� ��Page Down�� Ű�� ������ �÷��̾ ��/�Ʒ�(��
	�� y-��)�� �̵��Ѵ�.*/
	if (::GetKeyboardState(pKeyBuffer))
	{
		DWORD dwDirection = 0;
		if (pKeyBuffer[VK_W] & 0xF0)  dwDirection |= DIR_FORWARD;//w
		if (pKeyBuffer[VK_A] & 0xF0)  dwDirection |= DIR_LEFT;//w
		if (pKeyBuffer[VK_S] & 0xF0)  dwDirection |= DIR_BACKWARD;//w
		if (pKeyBuffer[VK_D] & 0xF0)  dwDirection |= DIR_RIGHT;//w
		if (pKeyBuffer[VK_UP] & 0xF0) dwDirection |= DIR_FORWARD;
		if (pKeyBuffer[VK_DOWN] & 0xF0) dwDirection |= DIR_BACKWARD;
		if (pKeyBuffer[VK_LEFT] & 0xF0) dwDirection |= DIR_LEFT;
		if (pKeyBuffer[VK_RIGHT] & 0xF0) dwDirection |= DIR_RIGHT;
		if (pKeyBuffer[VK_PRIOR] & 0xF0) dwDirection |= DIR_UP;
		if (pKeyBuffer[VK_NEXT] & 0xF0) dwDirection |= DIR_DOWN;

		//�Ѿ˹߻�
		if (pKeyBuffer[VK_LCONTROL] & 0xF0) {
			m_pPlayer->Fire();
		}

		//Ű �Է��� ������ �÷��̾ dwDirection �������� �̵��Ѵ�(�����δ� �ӵ� ���͸� �����Ѵ�).
		if (dwDirection) m_pPlayer->Move(dwDirection, 0.15f);
	}
	if (::GetCapture() == m_hWnd)
	{
		/*���콺�� ĸ��������(���콺 Ŭ���� �Ͼ����) ���콺�� �󸶸�ŭ �̵��Ͽ��� ���� ����Ѵ�. ���콺
		���� �Ǵ� ������ ��ư�� ������ ���� �޽���(WM_LBUTTONDOWN, WM_RBUTTONDOWN)�� ó����
		�� ���콺�� ĸ���Ͽ���. �׷��Ƿ� ���콺�� ĸ�ĵ� �����찡 ���� �������̸� ���콺 ��ư�� ���� ����
		���� Ŭ���̾�Ʈ �������� ������ ���¸� �ǹ��Ѵ�. ���콺 ��ư�� ������ ���¿��� ���콺�� �¿� �Ǵ�
		���Ϸ� �����̸� �÷��̾ x-�� �Ǵ� y-������ ȸ���Ѵ�.*/
		//���콺 Ŀ���� ȭ�鿡�� ���ش�(������ �ʰ� �Ѵ�).
		::SetCursor(NULL);
		POINT ptCursorPos;
		//���� ���콺 Ŀ���� ��ġ�� �����´�. 
		::GetCursorPos(&ptCursorPos);
		//���콺 ��ư�� ���� ���¿��� ���콺�� ������ ���� ���Ѵ�. 
		float cxMouseDelta = (float)(ptCursorPos.x - m_ptOldCursorPos.x) / 3.0f;
		float cyMouseDelta = (float)(ptCursorPos.y - m_ptOldCursorPos.y) / 3.0f;
		//���콺 Ŀ���� ��ġ�� ���콺�� �������� ��ġ�� �����Ѵ�.
		::SetCursorPos(m_ptOldCursorPos.x, m_ptOldCursorPos.y);
		if (cxMouseDelta || cyMouseDelta)
		{
			//���콺 �̵��� ������ �÷��̾ ȸ���Ѵ�.
			/*cxDelta�� y-���� ȸ���� ��Ÿ���� cyDelta�� x-���� ȸ���� ��Ÿ����. ������ ���콺 ��ư�� ������
			��� cxDelta�� z - ���� ȸ���� ��Ÿ����.*/
			if (pKeyBuffer[VK_RBUTTON] & 0xF0)
				m_pPlayer->Rotate(cyMouseDelta, 0.0f, -cxMouseDelta);
			else
				m_pPlayer->Rotate(cyMouseDelta, cxMouseDelta, 0.0f);
		}
	}

	//�÷��̾ ������ �̵��ϰ� ī�޶� �����Ѵ�. �������� ������ �ӵ� ���Ϳ� �����Ѵ�.
	m_pPlayer->Update(m_GameTimer.GetTimeElapsed());
}

void CGameFramework::AnimateObjects()
{
	float fTimeElapsed = m_GameTimer.GetTimeElapsed();
	if (m_pPlayer) {
		m_pPlayer->Animate(fTimeElapsed);
		if (m_pPlayer->bullets)
			for (int i = 0; i < m_pPlayer->curBulletCount; ++i)
				m_pPlayer->bullets[i]->Animate(fTimeElapsed);
	}
	if (m_pScene) m_pScene->Animate(fTimeElapsed);

}

void CGameFramework::FrameAdvance()
{
	//Ÿ�̸��� �ð��� ���ŵǵ��� �ϰ� ������ ����Ʈ�� ����Ѵ�. Tick(0.0f)�� ���غ���.
	m_GameTimer.Tick(60.0f);
	ProcessInput();
	AnimateObjects();
	ClearFrameBuffer(RGB(75, 45, 105));
	CCamera* pCamera = m_pPlayer->GetCamera();
	if (m_pScene) m_pScene->Render(m_hDCFrameBuffer, pCamera);
	//�÷��̾�(�����)�� �������Ѵ�. 
	if (m_pPlayer) {
		m_pPlayer->Render(m_hDCFrameBuffer, pCamera);
		if (m_pPlayer->bullets){
			for (int i = 0; i < m_pPlayer->curBulletCount; ++i){
				m_pPlayer->bullets[i]->Render(m_hDCFrameBuffer, pCamera);
				
			}
			//std::cout << "�Ѿ���ġ" << m_pPlayer->bullets[0]->GetPosition().x << '\n';
	
		}
		
		//std::cout << "�÷��̾���ġ" << m_pPlayer->GetPosition().x << '\n';
	}
	PresentFrameBuffer();
	//���� ������ ����Ʈ�� ������ ĸ��(Ÿ��Ʋ ��)�� ����Ѵ�.
	m_GameTimer.GetFrameRate(m_pszFrameRate + 12, 37);
	::SetWindowText(m_hWnd, m_pszFrameRate);
}