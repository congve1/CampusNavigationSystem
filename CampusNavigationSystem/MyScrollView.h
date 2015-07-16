#pragma once



// CMyScrollView view
#include "MyPictureControl.h"
class CMyScrollView : public CScrollView
{
	DECLARE_DYNCREATE(CMyScrollView)

protected:
	CMyScrollView();           // protected constructor used by dynamic creation
	virtual ~CMyScrollView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	DECLARE_MESSAGE_MAP()
private:
	CBitmap  m_Picture;
	CRect rect;
	int m_nWidth;
	int m_nHeight;
	int m_ratio;
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	void enlarge(int ratio = 10 / 9);
	void shrink(int ratio = 9 / 10);
};


