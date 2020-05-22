#include "stdafx.h"
#include "GraphicsPipeline.h"



//CGameObject* CGraphicsPipeline::m_pGameObject = NULL;
//CCamera* CGraphicsPipeline::m_pCamera = NULL;
//
//CPoint3D CGraphicsPipeline::Transform(CPoint3D& f3Model)
//{
//	CPoint3D f3World = m_pGameObject->WorldTransform(f3Model);
//	CPoint3D f3Camera = m_pCamera->CameraTransform(f3World);
//	CPoint3D f3Projection = m_pCamera->ProjectionTransform(f3Camera);
//	CPoint3D f3Screen = m_pCamera->ScreenTransform(f3Projection);
//
//	return(f3Screen);
//}
//
//CPoint3D CGraphicsPipeline::Project(CPoint3D& f3Model)
//{
//	CPoint3D f3World = m_pGameObject->WorldTransform(f3Model);
//	CPoint3D f3Camera = m_pCamera->CameraTransform(f3World);
//	CPoint3D f3Projection = m_pCamera->ProjectionTransform(f3Camera);
//
//	return(f3Projection);
//}
//
//CPoint3D CGraphicsPipeline::ScreenTransform(CPoint3D& f3Projection)
//{
//	CPoint3D f3Screen = m_pCamera->ScreenTransform(f3Projection);
//	return(f3Screen);
//}
//

//8주차 수정
XMFLOAT4X4* CGraphicsPipeline::m_pxmf4x4World = NULL;
XMFLOAT4X4* CGraphicsPipeline::m_pxmf4x4ViewProject = NULL;
CViewport* CGraphicsPipeline::m_pViewport = NULL;


XMFLOAT3 CGraphicsPipeline::Project(XMFLOAT3& xmf3Model)
{
	XMMATRIX xmmtxModelToProject =XMMatrixMultiply(XMLoadFloat4x4(m_pxmf4x4World),
			XMLoadFloat4x4(m_pxmf4x4ViewProject));
	XMFLOAT3 xmf3Project;
	XMStoreFloat3(&xmf3Project,
		XMVector3TransformCoord(XMLoadFloat3(&xmf3Model),
			xmmtxModelToProject));
	return(xmf3Project);
}

XMFLOAT3 CGraphicsPipeline::ScreenTransform(XMFLOAT3& xmf3Project)
{
	XMFLOAT3 f3Screen = xmf3Project;
	float fHalfWidth = m_pViewport->m_nWidth * 0.5f;
	float fHalfHeight = m_pViewport->m_nHeight * 0.5f;
	f3Screen.x = m_pViewport->m_nLeft + (xmf3Project.x * fHalfWidth) +fHalfWidth;
	f3Screen.y = m_pViewport->m_nTop + (-xmf3Project.y * fHalfHeight) +fHalfHeight;
	return(f3Screen);
}

