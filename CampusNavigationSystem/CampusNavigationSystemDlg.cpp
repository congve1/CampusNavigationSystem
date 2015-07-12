
// CampusNavigationSystemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CampusNavigationSystem.h"
#include "CampusNavigationSystemDlg.h"
#include "afxdialogex.h"
#include <fstream>
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
	DDX_Control(pDX, IDC_CMB_START_POINT, m_CmbStart);
	DDX_Control(pDX, IDC_CMB_END_POINT, m_CmbEnding);
}

BEGIN_MESSAGE_MAP(CCampusNavigationSystemDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CCampusNavigationSystemDlg::OnBnClickedButton2)
	ON_WM_CREATE()
	ON_COMMAND(ID_ABOUT, &CCampusNavigationSystemDlg::OnAbout)
	ON_COMMAND(ID_CSTARTPOINT, &CCampusNavigationSystemDlg::OnCstartpoint)
	ON_COMMAND(ID_CENDPOINT, &CCampusNavigationSystemDlg::OnCendpoint)
	ON_BN_CLICKED(IDC_BTN_CAL_ROUTE, &CCampusNavigationSystemDlg::OnClickedBtnCalRoute)
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
	std::fstream file;
	file.open("LocationsName.txt", std::ios::in);
	if (file.is_open()) {
		while (!file.eof()) {
			string tmp;
			file >> tmp;
			CString strtmp(tmp.c_str());
			m_CmbStart.AddString(strtmp);
			m_CmbEnding.AddString(strtmp);
		}
	}
	file.close();
	file.open("coordinates.txt", std::ios::in);
	for (int i = 0; i < NUM_OF_VERTICES; i++){
		
			file >> m_coordinates[i].x;
			file >> m_coordinates[i].y;
		
	}
	
	m_campus.Floyd();
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
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCampusNavigationSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

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

void CCampusNavigationSystemDlg::OnClickedBtnCalRoute()
{
	// TODO: Add your control notification handler code here
	static CClientDC dc(this);
	

	int nIndex = m_CmbStart.GetCurSel();
	CString strCBText;
	m_CmbStart.GetLBText(nIndex, strCBText);
	USES_CONVERSION;
	string tmpS(W2A(strCBText));	
	int startPoint = m_campus.getLocNumber(tmpS);
	nIndex = m_CmbEnding.GetCurSel();
	m_CmbEnding.GetLBText(nIndex, strCBText);
	string tmpE(W2A(strCBText));	
	int endingPoint = m_campus.getLocNumber(tmpE);
	path.clear();
	if (startPoint != endingPoint) {
		string ansPath;
		path = m_campus.printShortestPath(startPoint, endingPoint, ansPath);
		CString shortestLength;
		shortestLength.Format(_T("%d 米"), m_campus.getShortestRoadLength(startPoint, endingPoint));
		GetDlgItem(IDC_EDIT_MIN_LENGTH)->SetWindowTextW(shortestLength);
		CString CAnsPath(ansPath.c_str());
		GetDlgItem(IDC_EDIT_MIN_ROUTE)->SetWindowTextW(CAnsPath);
		printRoute(path,&dc);

	} else {
		MessageBox(_T("起点不能与终点重合"),_T("警告"));
	}

}


void CCampusNavigationSystemDlg::printRoute(vector<int> & nodes, CClientDC * dc)
{
	bool toLine = false;
	for (int i = nodes.size() - 1; i >= 0; i--) {
		if (toLine) {
			dc->LineTo(m_coordinates[nodes[i]]);
			dc->MoveTo(m_coordinates[nodes[i]]);
			//简单的延时
			Sleep(5000);
		} else {
			dc->MoveTo(m_coordinates[nodes[i]]);
			toLine = true;
		}
	}
}
void CCampusNavigationSystemDlg::clearRoute(vector<int> nodes,CClientDC * dc)
{
	InvalidateRect(NULL, FALSE);
	UpdateWindow();
}
