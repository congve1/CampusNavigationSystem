// CampusInfoDialog.cpp : implementation file
//

#include "stdafx.h"
#include "CampusNavigationSystem.h"
#include "CampusInfoDialog.h"
#include "afxdialogex.h"


// CCampusInfoDialog dialog

IMPLEMENT_DYNAMIC(CCampusInfoDialog, CDialog)

CCampusInfoDialog::CCampusInfoDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CCampusInfoDialog::IDD, pParent)
{

}
CCampusInfoDialog::CCampusInfoDialog(CWnd* pParent, vector<CString> & locNames)
	: CDialog(CCampusInfoDialog::IDD, pParent),m_locationNames(locNames)
{

}
CCampusInfoDialog::~CCampusInfoDialog()
{
}

void CCampusInfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_CAMPUS_INFO, m_tabControl);
}


BEGIN_MESSAGE_MAP(CCampusInfoDialog, CDialog)
	ON_BN_CLICKED(IDC_BTN_EXIT, &CCampusInfoDialog::OnClickedBtnExit)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_CAMPUS_INFO, &CCampusInfoDialog::OnTcnSelchangeTabCampusInfo)
END_MESSAGE_MAP()


// CCampusInfoDialog message handlers


void CCampusInfoDialog::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	CDialog::OnOK();
}


void CCampusInfoDialog::OnClickedBtnExit()
{
	// TODO: Add your control notification handler code here
	OnOK();
}


BOOL CCampusInfoDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  Add extra initialization here
	TCITEM item;
	item.mask = TCIF_TEXT;
	item.pszText = _T("SB");
	m_tabControl.InsertItem(0, &item);
	CRect rect;
	GetClientRect(rect);
	dlg.Create(IDD_DIALOG1, GetDlgItem(IDC_TAB_CAMPUS_INFO));
	rect.bottom -= 2;
	rect.left += 1;
	rect.right -= 3;
	rect.top += 25;
	dlg.MoveWindow(&rect);
	dlg.ShowWindow(SW_SHOW);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CCampusInfoDialog::OnTcnSelchangeTabCampusInfo(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
