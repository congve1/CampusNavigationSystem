// StartDialog.cpp : implementation file
//

#include "stdafx.h"
#include "CampusNavigationSystem.h"
#include "StartDialog.h"
#include "afxdialogex.h"


// CStartDialog dialog

IMPLEMENT_DYNAMIC(CStartDialog, CDialog)

CStartDialog::CStartDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CStartDialog::IDD, pParent)
{

}
CStartDialog::CStartDialog(CWnd * pParent, vector<CString> & locationsName)
	:CDialog(CStartDialog::IDD,pParent),m_locationsName(locationsName)
{

}
CStartDialog::~CStartDialog()
{
}

void CStartDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStartDialog, CDialog)
	ON_BN_CLICKED(IDC_BTN_OK, &CStartDialog::OnClickedBtnOk)
	ON_BN_CLICKED(IDC_BTN_CANCEL, &CStartDialog::OnClickedBtnCancel)
END_MESSAGE_MAP()


// CStartDialog message handlers


BOOL CStartDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	CComboBox * combobox = (CComboBox  *)GetDlgItem(IDC_CMB_START_POINT);
	for (int i = 0; i < m_locationsName.size(); i++) {
		combobox->AddString(m_locationsName[i]);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CStartDialog::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	CComboBox * comboBox = (CComboBox *)GetDlgItem(IDC_CMB_START_POINT);
	int nIndex = comboBox->GetCurSel();
	CString strCBText;
	comboBox->GetLBText(nIndex, strCBText);
	CComboBox * parentComboBox = (CComboBox *)GetParent()->GetDlgItem(IDC_CMB_START_POINT);
	parentComboBox->SelectString(nIndex, strCBText);
	CDialog::OnOK();
}


void CStartDialog::OnClickedBtnOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}


void CStartDialog::OnClickedBtnCancel()
{
	// TODO: Add your control notification handler code here
	::SendMessage(this->GetSafeHwnd(), WM_CLOSE, NULL, NULL);
}
