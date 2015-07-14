
// CampusNavigationSystemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CampusNavigationSystem.h"
#include "CampusNavigationSystemDlg.h"
#include "CampusInfoDialog.h"
#include "afxdialogex.h"
#include "StartDialog.h"
#include "EndDialog.h"
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
	, m_minRoute(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_Font.CreatePointFont(120, _T("微软雅黑"));

}

void CCampusNavigationSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CMB_START_POINT, m_CmbStart);
	DDX_Control(pDX, IDC_CMB_END_POINT, m_CmbEnding);
	DDX_Text(pDX, IDC_EDIT_MIN_ROUTE, m_minRoute);
	DDX_Control(pDX, IDC_EDIT_MIN_LENGTH, m_editMinLength);
	DDX_Control(pDX, IDC_EDIT_MIN_ROUTE, m_editMinRoute);
	DDX_Control(pDX, IDC_Building1, m_staticTexts[0]);
	DDX_Control(pDX, IDC_Building2, m_staticTexts[1]);
	DDX_Control(pDX, IDC_Building3, m_staticTexts[2]);
	DDX_Control(pDX, IDC_Building4, m_staticTexts[3]);
	DDX_Control(pDX, IDC_Building5, m_staticTexts[4]);
	DDX_Control(pDX, IDC_Building6, m_staticTexts[5]);
	DDX_Control(pDX, IDC_Building7, m_staticTexts[6]);
	DDX_Control(pDX, IDC_Building8, m_staticTexts[7]);
	DDX_Control(pDX, IDC_Building9, m_staticTexts[8]);
	DDX_Control(pDX, IDC_Building10, m_staticTexts[9]);
	DDX_Control(pDX, IDC_Building11, m_staticTexts[10]);
	DDX_Control(pDX, IDC_Building12, m_staticTexts[11]);
	DDX_Control(pDX, IDC_Building13, m_staticTexts[12]);
	DDX_Control(pDX, IDC_Building14, m_staticTexts[13]);
	DDX_Control(pDX, IDC_Building15, m_staticTexts[14]);
	DDX_Control(pDX, IDC_Building16, m_staticTexts[15]);
	DDX_Control(pDX, IDC_Building17, m_staticTexts[16]);
	DDX_Control(pDX, IDC_Building18, m_staticTexts[17]);
	DDX_Control(pDX, IDC_Building19, m_staticTexts[18]);
	DDX_Control(pDX, IDC_STATIC5, m_Static5);
	DDX_Control(pDX, IDC_STATIC1, m_Static1);
	DDX_Control(pDX, IDC_STATIC2, m_Static2);
	DDX_Control(pDX, IDC_STATIC3, m_Static3);
	DDX_Control(pDX, IDC_STATIC4, m_Static4);
	DDX_Control(pDX, IDC_BTN_CAL_ROUTE, m_BtnCalRoute);
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
	ON_COMMAND(ID_CAMPUS_INFO, &CCampusNavigationSystemDlg::OnCampusInfo)
	ON_COMMAND(ID_MITEM_EXIT, &CCampusNavigationSystemDlg::OnExit)
	ON_WM_MEASUREITEM()
	ON_WM_DRAWITEM()
	ON_WM_CTLCOLOR()
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
	m_editMinLength.SetFont(&m_Font);
	m_editMinRoute.SetFont(&m_Font);
	m_Static1.SetFont(&m_Font);
	m_Static2.SetFont(&m_Font);
	m_Static3.SetFont(&m_Font);
	m_Static4.SetFont(&m_Font);
	m_Static5.SetFont(&m_Font);
	m_CmbEnding.SetFont(&m_Font);
	m_CmbStart.SetFont(&m_Font);
	m_BtnCalRoute.SetFont(&m_Font);
	for (int i = 0; i < NUM_OF_BUILDINGS; i++) {
		m_staticTexts[i].SetFont();
	}
	std::fstream file;
	file.open("LocationsName.txt", std::ios::in);
	if (file.is_open()) {
		//从文件中读取建筑名称
		while (!file.eof()) {
			string tmp;
			file >> tmp;
			CString strtmp(tmp.c_str());
			m_locationsName.push_back(strtmp);
			m_CmbStart.AddString(strtmp);
			m_CmbEnding.AddString(strtmp);
		}
	} else {
		MessageBox(_T("LocationsName.txt不存在"), _T("警告"));
	}
	file.close();
	//从文件中读取节点的坐标
	file.open("coordinates.txt", std::ios::in);
	if (!file.is_open()) {
		MessageBox(_T("coordinates.txt不存在"), _T("警告"));
	} else {
		for (int i = 0; i < NUM_OF_VERTICES; i++) {

			file >> m_coordinates[i].x;
			file >> m_coordinates[i].y;

		}
	}
	
	//使用弗洛伊德算法，求任意两点间的最短距离
	m_campus.Floyd();
	m_menu.LoadMenuW(IDR_MENU1);
	m_menu.ChangeMeuItem(&m_menu);
	SetMenu(&m_menu);
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
	CStartDialog dlg(NULL, m_locationsName);
	dlg.DoModal();
}


void CCampusNavigationSystemDlg::OnCendpoint()
{
	// TODO: Add your command handler code here
	CEndDialog dlg(NULL, m_locationsName);
	dlg.DoModal();
}

void CCampusNavigationSystemDlg::OnClickedBtnCalRoute()
{
	// TODO: Add your control notification handler code here
	static CClientDC dc(this);
	GetDlgItem(IDC_EDIT_MIN_LENGTH)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDIT_MIN_ROUTE)->SetWindowTextW(_T(""));
	clearRoute(path, &dc);
	int nIndex = m_CmbStart.GetCurSel();
	CString strCBText;
	m_CmbStart.GetLBText(nIndex, strCBText);
	//USES_CONVERSION;
	//string tmpS(W2A(strCBText));	
	string tmpS = WCharToAnsi(strCBText);
	int startPoint = m_campus.getLocNumber(tmpS);
	nIndex = m_CmbEnding.GetCurSel();
	m_CmbEnding.GetLBText(nIndex, strCBText);
	//string tmpE(W2A(strCBText));	
	string tmpE=WCharToAnsi(strCBText);
	int endingPoint = m_campus.getLocNumber(tmpE);
	path.clear();
	if (startPoint != endingPoint) {
		string ansPath;
		path = m_campus.printShortestPath(startPoint, endingPoint, ansPath);
		CString shortestLength;
		shortestLength.Format(_T("%d 米"), m_campus.getShortestRoadLength(startPoint, endingPoint));
		GetDlgItem(IDC_EDIT_MIN_LENGTH)->SetWindowTextW(shortestLength);
		CString CAnsPath(ansPath.c_str());
		m_minRoute.Delete(0, m_minRoute.GetLength());
		m_minRoute += CAnsPath;
		UpdateData(FALSE);
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
		} else {
			dc->MoveTo(m_coordinates[nodes[i]]);
			toLine = true;
		}
		if (i != 0)
			Sleep(1);
	}
}
void CCampusNavigationSystemDlg::clearRoute(vector<int> nodes,CClientDC * dc)
{
	InvalidateRect(NULL, FALSE);
	UpdateWindow();
}
void CCampusNavigationSystemDlg::OnCampusInfo()
{
	// TODO: Add your command handler code here
	CCampusInfoDialog dlg(NULL, m_locationsName);
	dlg.DoModal();
}


string CCampusNavigationSystemDlg::WCharToAnsi(LPCWSTR pwszSrc)
{
	/*WideCharToMultiByte(
		UNIT CodePage, DWORD dwFlags, LPCWSTR lpWideCharStr,
		int cchWideChar, LPSTR IpMultiByteStr, int cchMultiByteStr,
		LPCSTR lpDefaultChar, LPBOOL pfUsedDefaultChar
		);,该函数映射一个unicode字符串到一个多字节字符串
	  第一个参数指定执行转换的代码页 CP_ACP为ANSI代码页
	  第二个参数允许你进行额外的控制 
	  第三个参数指定要转换为宽字节字符串的缓冲区
	  第四个参数指定由第三个参数指定的缓冲区的字符个数
	  第五个参数指向接受被转换字符串的缓冲区
	  第六个参数指定由第五个参数指向的缓冲区的最大值
	  第七个参数，若遇到一个不能转换的宽字符，函数会使用该参数指向的字符
	  第八个参数，至少一有一个字符不能转换为多字节形式函数会把这个变量设为TURE
	  若函数运行成功，并且cchMultiBye为零，返回值是接收到带转换字符串的缓冲区所必须的字节数
	*/
	int len = WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, NULL, 0, NULL, NULL);
	if(len <= 0) return string("");
	char * pszDst = new char[len];
	if (NULL == pszDst) return string("");
	WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, pszDst, len, NULL, NULL);
	pszDst[len - 1] = 0;
	string strTmp(pszDst);
	delete pszDst;
	return strTmp;
}
void CCampusNavigationSystemDlg::OnExit()
{
	// TODO: Add your command handler code here
	CDialog::OnOK();
}
//过滤掉按下ESC的消息相应
BOOL CCampusNavigationSystemDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN &&
		pMsg->wParam == VK_ESCAPE) {
		return FALSE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CCampusNavigationSystemDlg::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	// TODO: Add your message handler code here and/or call default
	if (lpMeasureItemStruct->CtlType == ODT_MENU) {
		//如果类型是菜单
		m_menu.MeasureItem(lpMeasureItemStruct);
	}else
	CDialog::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}


void CCampusNavigationSystemDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: Add your message handler code here and/or call default
	if (lpDrawItemStruct->CtlType == ODT_MENU) {
		//如果类型是菜单
		m_menu.DrawItem(lpDrawItemStruct);
	} else
	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}


HBRUSH CCampusNavigationSystemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	for (int i = 0; i < NUM_OF_BUILDINGS; i++) {
		if (pWnd == &m_staticTexts[i]) {
			pDC->SetBkMode(TRANSPARENT);
		}
	}
	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
