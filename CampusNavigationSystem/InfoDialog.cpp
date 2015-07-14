// InfoDialog.cpp : implementation file
//

#include "stdafx.h"
#include "CampusNavigationSystem.h"
#include "InfoDialog.h"
#include "afxdialogex.h"


// CInfoDialog dialog

IMPLEMENT_DYNAMIC(CInfoDialog, CDialog)

CInfoDialog::CInfoDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CInfoDialog::IDD, pParent)
{

}

CInfoDialog::~CInfoDialog()
{
}

void CInfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_INFO, m_editSimpleInfo);
	DDX_Control(pDX, IDC_PICTURE, m_Picture);
}


BEGIN_MESSAGE_MAP(CInfoDialog, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CInfoDialog message handlers


BOOL CInfoDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	m_Font.CreatePointFont(140, _T("Î¢ÈíÑÅºÚ"));
	m_editSimpleInfo.SetFont(&m_Font);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


HBRUSH CInfoDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	if (pWnd == &m_editSimpleInfo) {
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(213, 25, 0));
		HBRUSH newHbr = CreateSolidBrush(GetSysColor(COLOR_BTNFACE));
		return newHbr;
	}
	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
void CInfoDialog::setImage(UINT resID)
{
	CRect rect;
	CStatic * toGetRect = (CStatic *)GetDlgItem(IDC_TO_GET_RECT);
	toGetRect->GetClientRect(&rect);
	m_Picture.setImage(resID,rect);
}