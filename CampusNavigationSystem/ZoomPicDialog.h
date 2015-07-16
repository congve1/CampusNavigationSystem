#pragma once

#include "MyScrollView.h"
// CZoomPicDialog dialog

class CZoomPicDialog : public CDialog
{
	DECLARE_DYNAMIC(CZoomPicDialog)

public:
	CZoomPicDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CZoomPicDialog();

// Dialog Data
	enum { IDD = IDD_ZOOM_PIC_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CMyScrollView * m_picScrollView;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedBtnEnlarge();
	afx_msg void OnClickedBtnShorten();
};
