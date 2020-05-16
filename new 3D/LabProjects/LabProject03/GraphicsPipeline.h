#pragma once

#include "GameObject.h"
#include "Camera.h"


//8���� ����
//class CGraphicsPipeline
//{
//private:
//	static CGameObject*		m_pGameObject;
//	static CCamera*			m_pCamera;
//
//public:
//	static void SetGameObject(CGameObject* pGameObject) { m_pGameObject = pGameObject; }
//	static void SetCamera(CCamera* pCamera) { m_pCamera = pCamera; }
//
//	static CPoint3D ScreenTransform(CPoint3D& f3Projection);
//	static CPoint3D Project(CPoint3D& f3Model);
//	static CPoint3D Transform(CPoint3D& f3Model);
//};


class CGraphicsPipeline
{
private:
	//���� �������� ���� ��ü�� ���� ��ȯ ����̴�.
	static XMFLOAT4X4* m_pxmf4x4World;
	//���� ī�޶� ��ü�� (ī�޶� ��ȯ ��� * ���� ���� ��ȯ ���)�̴�.
	static XMFLOAT4X4* m_pxmf4x4ViewProject;
	static CViewport* m_pViewport;
public:
	static void SetWorldTransform(XMFLOAT4X4* pxmf4x4World) {
		m_pxmf4x4World = pxmf4x4World;
	}
	static void SetViewProjectTransform(XMFLOAT4X4* pxmf4x4ViewProject)
	{
		m_pxmf4x4ViewProject = pxmf4x4ViewProject;
	}
	static void SetViewport(CViewport* pViewport) {
		m_pViewport =
			pViewport;
	}
	static XMFLOAT3 ScreenTransform(XMFLOAT3& xmf3Project);
	static XMFLOAT3 Project(XMFLOAT3& xmf3Model);
};