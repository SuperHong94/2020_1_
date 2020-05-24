#pragma once

#include "GameObject.h"
#include "Camera.h"
#include "Player.h"  //8������ �߰�



class CScene
{
public:
	CScene(CPlayer* pPlayer) { m_pPlayer = pPlayer; 
	//��ŷ����
	}
	virtual ~CScene() { }
private:
	int m_nObjects = 0;
	CExplosion** m_ppObjects = NULL;
	CPlayer* m_pPlayer = NULL;
	CMap* m_pMap = NULL;


	//CExplosion** m_ppExplosions = NULL;
public:
	bool IsPickingObject(int x, int y,CCamera* pCamera);
	bool IsCollision();
	bool IsCollision(XMFLOAT3); //��ŷ �˻�
	int GetObjectsCount();
	virtual void BuildObjects();
	virtual void ReleaseObjects();
	virtual void Animate(float fElapsedTime);
	virtual void Render(HDC hDCFrameBuffer, CCamera* pCamera);
	//������ �޽���(Ű����, ���콺)�� ó���Ѵ�. 
	virtual void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID,
		WPARAM wParam, LPARAM lParam) { }
	virtual void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID,
		WPARAM wParam, LPARAM lParam) { }
};
