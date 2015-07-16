// MyScrollView.cpp : implementation file
//

#include "stdafx.h"
#include "CampusNavigationSystem.h"
#include "MyScrollView.h"


// CMyScrollView

IMPLEMENT_DYNCREATE(CMyScrollView, CScrollView)

CMyScrollView::CMyScrollView()
{
	
}

CMyScrollView::~CMyScrollView()
{
}


BEGIN_MESSAGE_MAP(CMyScrollView, CScrollView)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CMyScrollView drawing

void CMyScrollView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CMyScrollView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	static bool isLoaded = false;
	CRect rect;
	GetClientRect(rect);
	if (!isLoaded) {
		CDC * m_pMemDC = new CDC;
		m_Picture.LoadBitmapW(IDB_MAP3D);
		isLoaded = !isLoaded;
		m_nWidth = rect.Width();
		m_nHeight = rect.Height();
		m_pMemDC->CreateCompatibleDC(pDC);
		CBitmap* pOldBitmap = m_pMemDC->SelectObject(&m_Picture);
		pDC->SetStretchBltMode(COLORONCOLOR);
		pDC->StretchBlt(rect.left, rect.top, m_nWidth, m_nHeight, m_pMemDC, 0, 0,
						m_nWidth, m_nHeight, SRCCOPY);
		m_pMemDC->SelectObject(pOldBitmap);
	} else {	
		CDC memDC;
		memDC.CreateCompatibleDC(pDC);
		CBitmap bitmap;
		bitmap.CreateCompatibleBitmap(pDC, m_nWidth, m_nHeight);
		CBitmap * pOldBitmap = memDC.SelectObject(&bitmap);
		memDC.SetStretchBltMode(COLORONCOLOR);
		memDC.StretchBlt(rect.left, rect.top, m_nWidth, m_nHeight, pDC, 0, 0,
						 m_nHeight, m_nHeight, SRCCOPY);
		pDC->BitBlt(0, 0, m_nHeight, m_nWidth, &memDC, 0, 0, SRCCOPY);
		memDC.SelectObject(pOldBitmap);
		memDC.DeleteDC();
		bitmap.DeleteObject();		
	}
	
}


// CMyScrollView diagnostics

#ifdef _DEBUG
void CMyScrollView::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyScrollView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyScrollView message handlers


BOOL CMyScrollView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	//return CScrollView::OnEraseBkgnd(pDC);
	return FALSE;
}
void CMyScrollView::enlarge(int ratio)
{
	m_ratio = ratio;
	CRect rect;
	GetClientRect(rect);
	InvalidateRect(rect);
	UpdateWindow();
}
void CMyScrollView::shrink(int ratio)
{
	m_ratio = ratio;
	CRect rect;
	GetClientRect(rect);
	InvalidateRect(rect);
	UpdateWindow();
}