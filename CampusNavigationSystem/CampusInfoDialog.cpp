// CampusInfoDialog.cpp : implementation file
//

#include "stdafx.h"
#include "CampusNavigationSystem.h"
#include "CampusInfoDialog.h"
#include "afxdialogex.h"
#include <fstream>
using std::fstream;
using std::ios;

// CCampusInfoDialog dialog

IMPLEMENT_DYNAMIC(CCampusInfoDialog, CDialog)

CCampusInfoDialog::CCampusInfoDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CCampusInfoDialog::IDD, pParent)
{

}
CCampusInfoDialog::CCampusInfoDialog(CWnd* pParent, vector<CString> & locNames, int nIndex)
	: CDialog(CCampusInfoDialog::IDD, pParent), m_locationNames(locNames), m_StartPage(nIndex)
{
	m_picturesID[0] = IDB_PIC1_1; m_picturesID[10] = IDB_PIC11_1;
	m_picturesID[1] = IDB_PIC2_1; m_picturesID[11] = IDB_PIC12_1;
	m_picturesID[2] = IDB_PIC3_1; m_picturesID[12] = IDB_PIC13_1;
	m_picturesID[3] = IDB_PIC4_1; m_picturesID[13] = IDB_PIC14_1;
	m_picturesID[4] = IDB_PIC5_1; m_picturesID[14] = IDB_PIC15_1;
	m_picturesID[5] = IDB_PIC6_1; m_picturesID[15] = IDB_PIC16_1;
	m_picturesID[6] = IDB_PIC7_1; m_picturesID[16] = IDB_PIC17_1;
	m_picturesID[7] = IDB_PIC8_1; m_picturesID[17] = IDB_PIC18_1;
	m_picturesID[8] = IDB_PIC9_1; m_picturesID[18] = IDB_PIC19_1;
	m_picturesID[9] = IDB_PIC10_1;
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
	fstream file;
	TCITEM item;
	item.mask = TCIF_TEXT;
	file.open("buildingsInfo.txt");
	CRect rect;
	GetClientRect(rect);
	rect.bottom -= 2;
	rect.left += 1;
	rect.right -= 3;
	rect.top += 25;
	if (!file.is_open()) {
		MessageBox(_T("buildingsInfo.txt²»´æÔÚ"), _T("¾¯¸æ"));
	} else {
		for (int i = 0; i < NUM_OF_BUILDINGS; i++) {
			string tmp;
			for (int j = 0; j < 10; j++) {
				string parts;
				getline(file, parts);
				tmp += parts;
				if (parts != "") {
					tmp += "\r\n";
				}
			}			
			CString Ctmp(tmp.c_str());
			m_buildingsInfo[i] = Ctmp;
			item.pszText = (LPWSTR)(LPCWSTR)m_locationNames[i];
			m_tabControl.InsertItem(i, &item);
			m_dialogs[i].Create(IDD_DIALOG1, GetDlgItem(IDC_TAB_CAMPUS_INFO));
			m_dialogs[i].MoveWindow(&rect);
			m_dialogs[i].ShowWindow(SW_HIDE);
		    (m_dialogs[i].GetDlgItem(IDC_EDIT_INFO))->SetWindowTextW(m_buildingsInfo[i]);
			m_dialogs[i].setImage(m_picturesID[i]);
		}
	}
	file.close();
	m_dialogs[m_StartPage].ShowWindow(SW_SHOW);
	m_tabControl.SetCurSel(m_StartPage);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CCampusInfoDialog::OnTcnSelchangeTabCampusInfo(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	showTab(m_tabControl.GetCurSel());
	*pResult = 0;
}
void CCampusInfoDialog::showTab(int nIndex)
{
	for (int i = 0; i < NUM_OF_BUILDINGS; i++) {
		if (i != nIndex) {
			m_dialogs[i].ShowWindow(SW_HIDE);
		} else {
			m_dialogs[i].ShowWindow(SW_SHOW);
		}
	}
}
