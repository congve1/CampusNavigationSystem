
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
	m_Font.CreatePointFont(120, _T("΢���ź�"));

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
	ON_STN_DBLCLK(IDC_Building1, &CCampusNavigationSystemDlg::OnDblclkBuilding1)
	ON_STN_DBLCLK(IDC_Building10, &CCampusNavigationSystemDlg::OnDblclkBuilding10)
	ON_STN_DBLCLK(IDC_Building11, &CCampusNavigationSystemDlg::OnDblclkBuilding11)
	ON_STN_DBLCLK(IDC_Building12, &CCampusNavigationSystemDlg::OnDblclkBuilding12)
	ON_STN_DBLCLK(IDC_Building13, &CCampusNavigationSystemDlg::OnDblclkBuilding13)
	ON_STN_DBLCLK(IDC_Building14, &CCampusNavigationSystemDlg::OnDblclkBuilding14)
	ON_STN_DBLCLK(IDC_Building15, &CCampusNavigationSystemDlg::OnDblclkBuilding15)
	ON_STN_DBLCLK(IDC_Building16, &CCampusNavigationSystemDlg::OnDblclkBuilding16)
	ON_STN_DBLCLK(IDC_Building17, &CCampusNavigationSystemDlg::OnDblclkBuilding17)
	ON_STN_DBLCLK(IDC_Building18, &CCampusNavigationSystemDlg::OnDblclkBuilding18)
	ON_STN_DBLCLK(IDC_Building19, &CCampusNavigationSystemDlg::OnDblclkBuilding19)
	ON_STN_DBLCLK(IDC_Building2, &CCampusNavigationSystemDlg::OnDblclkBuilding2)
	ON_STN_DBLCLK(IDC_Building3, &CCampusNavigationSystemDlg::OnDblclkBuilding3)
	ON_STN_DBLCLK(IDC_Building4, &CCampusNavigationSystemDlg::OnDblclkBuilding4)
	ON_STN_DBLCLK(IDC_Building5, &CCampusNavigationSystemDlg::OnDblclkBuilding5)
	ON_STN_DBLCLK(IDC_Building6, &CCampusNavigationSystemDlg::OnDblclkBuilding6)
	ON_STN_DBLCLK(IDC_Building7, &CCampusNavigationSystemDlg::OnDblclkBuilding7)
	ON_STN_DBLCLK(IDC_Building8, &CCampusNavigationSystemDlg::OnDblclkBuilding8)
	ON_STN_DBLCLK(IDC_Building9, &CCampusNavigationSystemDlg::OnDblclkBuilding9)
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
	ModifyStyle(WS_THICKFRAME,0,SWP_FRAMECHANGED | SWP_DRAWFRAME);
	std::fstream file;
	file.open("LocationsName.txt", std::ios::in);
	if (file.is_open()) {
		//���ļ��ж�ȡ��������
		while (!file.eof()) {
			string tmp;
			file >> tmp;
			CString strtmp(tmp.c_str());
			m_locationsName.push_back(strtmp);
			m_CmbStart.AddString(strtmp);
			m_CmbEnding.AddString(strtmp);
		}
	} else {
		MessageBox(_T("LocationsName.txt������"), _T("����"));
	}
	file.close();
	//���ļ��ж�ȡ�ڵ������
	file.open("coordinates.txt", std::ios::in);
	if (!file.is_open()) {
		MessageBox(_T("coordinates.txt������"), _T("����"));
	} else {
		for (int i = 0; i < NUM_OF_VERTICES; i++) {

			file >> m_coordinates[i].x;
			file >> m_coordinates[i].y;

		}
	}
	
	//ʹ�ø��������㷨����������������̾���
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
		shortestLength.Format(_T("%d ��"), m_campus.getShortestRoadLength(startPoint, endingPoint));
		GetDlgItem(IDC_EDIT_MIN_LENGTH)->SetWindowTextW(shortestLength);
		CString CAnsPath(ansPath.c_str());
		m_minRoute.Delete(0, m_minRoute.GetLength());
		m_minRoute += CAnsPath;
		UpdateData(FALSE);
		printRoute(path,&dc);

	} else {
		MessageBox(_T("��㲻�����յ��غ�"),_T("����"));
	}

}
void CCampusNavigationSystemDlg::printRoute(vector<int> & nodes, CClientDC * dc)
{
	bool toLine = false;
	CPen pen;//���û���
	pen.CreatePen(PS_SOLID, 2 , RGB(100, 100, 100));	
	CBrush brush;
	brush.CreateSolidBrush(RGB(0, 0, 255));
	CBrush * pOldBrush = dc->SelectObject(&brush);
	dc->Ellipse(m_coordinates[nodes[nodes.size() - 1]].x - 6,
				m_coordinates[nodes[nodes.size() - 1]].y - 6,
				m_coordinates[nodes[nodes.size() - 1]].x + 6,
				m_coordinates[nodes[nodes.size() - 1]].y + 6);
	CPen * pOldPen = dc->SelectObject(&pen);
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
	dc->SelectObject(pOldPen);
	pen.DeleteObject();
	dc->SelectObject(pOldBrush);
	brush.DeleteObject();
	brush.CreateSolidBrush(RGB(0,255,0));
	pOldBrush = dc->SelectObject(&brush);
	dc->Ellipse(m_coordinates[nodes[0]].x -	6,
				m_coordinates[nodes[0]].y - 6,
				m_coordinates[nodes[0]].x + 6,
				m_coordinates[nodes[0]].y + 6);
	dc->SelectObject(pOldBrush);
	brush.DeleteObject();
}
void CCampusNavigationSystemDlg::clearRoute(vector<int> nodes,CClientDC * dc)
{
	CRect rect;
	GetDlgItem(IDC_LOADMAP)->GetClientRect(rect);
	InvalidateRect(rect,false);
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
		);,�ú���ӳ��һ��unicode�ַ�����һ�����ֽ��ַ���
	  ��һ������ָ��ִ��ת���Ĵ���ҳ CP_ACPΪANSI����ҳ
	  �ڶ���������������ж���Ŀ��� 
	  ����������ָ��Ҫת��Ϊ���ֽ��ַ����Ļ�����
	  ���ĸ�����ָ���ɵ���������ָ���Ļ��������ַ�����
	  ���������ָ����ܱ�ת���ַ����Ļ�����
	  ����������ָ���ɵ��������ָ��Ļ����������ֵ
	  ���߸�������������һ������ת���Ŀ��ַ���������ʹ�øò���ָ����ַ�
	  �ڰ˸�����������һ��һ���ַ�����ת��Ϊ���ֽ���ʽ����������������ΪTURE
	  ���������гɹ�������cchMultiByeΪ�㣬����ֵ�ǽ��յ���ת���ַ����Ļ�������������ֽ���
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
//���˵�����ESC����Ϣ��Ӧ
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
		//��������ǲ˵�
		m_menu.MeasureItem(lpMeasureItemStruct);
	}else
	CDialog::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}


void CCampusNavigationSystemDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: Add your message handler code here and/or call default
	if (lpDrawItemStruct->CtlType == ODT_MENU) {
		//��������ǲ˵�
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
			pDC->SetTextColor(RGB(196, 27,27));
			return (HBRUSH)GetStockObject(NULL_BRUSH);
		}
	}
	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
void CCampusNavigationSystemDlg::OnDblclkBuilding1()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[0].OpenDialog(m_locationsName, 0);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding2()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[1].OpenDialog(m_locationsName, 1);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding3()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[2].OpenDialog(m_locationsName, 2);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding4()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[3].OpenDialog(m_locationsName, 3);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding5()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[4].OpenDialog(m_locationsName, 4);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding6()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[5].OpenDialog(m_locationsName, 5);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding7()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[6].OpenDialog(m_locationsName, 6);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding8()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[7].OpenDialog(m_locationsName, 7);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding9()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[8].OpenDialog(m_locationsName, 8);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding10()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[9].OpenDialog(m_locationsName, 9);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding11()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[10].OpenDialog(m_locationsName, 10);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding12()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[11].OpenDialog(m_locationsName, 11);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding13()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[12].OpenDialog(m_locationsName, 12);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding14()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[13].OpenDialog(m_locationsName, 13);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding15()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[14].OpenDialog(m_locationsName, 14);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding16()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[15].OpenDialog(m_locationsName, 15);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding17()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[16].OpenDialog(m_locationsName, 16);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding18()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[17].OpenDialog(m_locationsName, 17);
}
void CCampusNavigationSystemDlg::OnDblclkBuilding19()
{
	// TODO: Add your control notification handler code here
	m_staticTexts[18].OpenDialog(m_locationsName, 18);
}