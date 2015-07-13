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
}


BEGIN_MESSAGE_MAP(CCampusInfoDialog, CDialog)
END_MESSAGE_MAP()


// CCampusInfoDialog message handlers
