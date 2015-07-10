
// CampusNavigationSystemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CampusNavigationSystem.h"
#include "CampusNavigationSystemDlg.h"
#include "afxdialogex.h"
#include "CLoadImages.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCampusNavigationSystemDlg dialog



CCampusNavigationSystemDlg::CCampusNavigationSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCampusNavigationSystemDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCampusNavigationSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCampusNavigationSystemDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_BUTTON1, &CCampusNavigationSystemDlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON2, &CCampusNavigationSystemDlg::OnBnClickedButton2)
ON_WM_CREATE()
ON_COMMAND(ID_ABOUT, &CCampusNavigationSystemDlg::OnAbout)
ON_COMMAND(ID_CSTARTPOINT, &CCampusNavigationSystemDlg::OnCstartpoint)
ON_COMMAND(ID_CENDPOINT, &CCampusNavigationSystemDlg::OnCendpoint)
//ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CCampusNavigationSystemDlg::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// CCampusNavigationSystemDlg message handlers

BOOL CCampusNavigationSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCampusNavigationSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCampusNavigationSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	
	CStatic * loadMap = (CStatic *)GetDlgItem(IDC_LOADMAP);
	CRect crect;
	loadMap->GetClientRect(&crect);
	int width = crect.Width();
	int height = crect.Height();


}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCampusNavigationSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CCampusNavigationSystemDlg::OnBnClickedButton1()
//{
//	// TODO: Add your control notification handler code here
//}


void CCampusNavigationSystemDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CDialog dlg(IDD_ABOUTBOX);
	dlg.DoModal();
}


int CCampusNavigationSystemDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	return 0;
}


void CCampusNavigationSystemDlg::OnAbout()
{
	// TODO: Add your command handler code here
	CDialog dlg(IDD_ABOUTBOX);
	dlg.DoModal();
}


void CCampusNavigationSystemDlg::OnCstartpoint()
{
	// TODO: Add your command handler code here
	CDialog dlg(IDD_SET_START_POINT);
	dlg.DoModal();
}


void CCampusNavigationSystemDlg::OnCendpoint()
{
	// TODO: Add your command handler code here
	CDialog dlg(IDD_SET_END_POINT);
	dlg.DoModal();
}


//void CCampusNavigationSystemDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
//	// TODO: Add your control notification handler code here
//	*pResult = 0;
//}
