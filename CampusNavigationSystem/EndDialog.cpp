// EndDialog.cpp : implementation file
//

#include "stdafx.h"
#include "CampusNavigationSystem.h"
#include "EndDialog.h"
#include "afxdialogex.h"


// CEndDialog dialog

IMPLEMENT_DYNAMIC(CEndDialog, CDialog)

CEndDialog::CEndDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CEndDialog::IDD, pParent)
{

}
CEndDialog::CEndDialog(CWnd* pParent, vector<CString> & locNames)
	: CDialog(CEndDialog::IDD, pParent), m_locationName(locNames)
{

}
CEndDialog::~CEndDialog()
{
}

void CEndDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEndDialog, CDialog)
	ON_BN_CLICKED(IDC_BTN_OK, &CEndDialog::OnClickedBtnOk)
	ON_BN_CLICKED(IDC_BTN_CANCEL, &CEndDialog::OnClickedBtnCancel)
END_MESSAGE_MAP()


// CEndDialog message handlers


void CEndDialog::OnClickedBtnOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}


void CEndDialog::OnClickedBtnCancel()
{
	// TODO: Add your control notification handler code here
	::SendMessage(this->GetSafeHwnd(), WM_CLOSE, NULL, NULL);
}


void CEndDialog::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	CComboBox * chComboBox = (CComboBox *)GetDlgItem(IDC_CMB_END_POINT);
	CComboBox * parComboBox = (CComboBox *)GetParent()->GetDlgItem(IDC_CMB_END_POINT);
	int nIndx = chComboBox->GetCurSel();
	CString tmp;
	chComboBox->GetLBText(nIndx, tmp);
	parComboBox->SelectString(nIndx, tmp);
	CDialog::OnOK();
}


BOOL CEndDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	CComboBox * comobox = (CComboBox *)GetDlgItem(IDC_CMB_END_POINT);
	for (int i = 0; i < m_locationName.size(); i++) {
		comobox->AddString(m_locationName[i]);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
