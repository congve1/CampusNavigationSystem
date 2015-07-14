#pragma once
#include "ReadOnlyEdit.h"
#include "Graph.h"
#include "afxwin.h"
#include "MyPictureControl.h"
// CInfoDialog dialog
class CInfoDialog : public CDialog
{
	DECLARE_DYNAMIC(CInfoDialog)

public:
	CInfoDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CInfoDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CReadOnlyEdit m_editSimpleInfo;

public:
	virtual BOOL OnInitDialog();
	void setImage(UINT resID);
private:
	CFont m_Font;
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CMyPictureControl m_Picture;
};
