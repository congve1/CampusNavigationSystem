// MyPictureControl.cpp : implementation file
//

#include "stdafx.h"
#include "CampusNavigationSystem.h"
#include "MyPictureControl.h"


// CMyPictureControl

IMPLEMENT_DYNAMIC(CMyPictureControl, CStatic)

CMyPictureControl::CMyPictureControl()
{

}

CMyPictureControl::~CMyPictureControl()
{
}


BEGIN_MESSAGE_MAP(CMyPictureControl, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CMyPictureControl message handlers

void CMyPictureControl::setImage(UINT resID,CRect & rect)
{
	m_bitMap.LoadBitmapW(resID);
	m_rect = rect;
}


void CMyPictureControl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CStatic::OnPaint() for painting messages
	
	//HBRUSH bursh = (HBRUSH)::GetStockObject(GRAY_BRUSH);
	//::FillRect(dc.m_hDC, &m_rect, bursh);//填充背景
	dc.SetStretchBltMode(HALFTONE);
	//将位图选进内存DC中
	CDC memdc;
	memdc.CreateCompatibleDC(&dc);
	CBitmap * pOldBmp = memdc.SelectObject(&m_bitMap);
	//获得位图参数
	BITMAP bmp;
	m_bitMap.GetBitmap(&bmp);
	dc.StretchBlt(m_rect.left, m_rect.top, m_rect.Width() - 12, m_rect.Height() - 20, &memdc, 0, 0,
				  bmp.bmWidth, bmp.bmHeight, SRCCOPY);
	memdc.SelectObject(&pOldBmp);//还原画刷
}
