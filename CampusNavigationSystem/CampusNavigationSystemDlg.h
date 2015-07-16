
// CampusNavigationSystemDlg.h : header file
//

#pragma once
#include "Graph.h"
#include "afxwin.h"
#include "ReadOnlyEdit.h"
#include "MyMenu.h"
#include "MyStaticText.h"
#include "CampusInfoDialog.h"
// CCampusNavigationSystemDlg dialog
class CCampusNavigationSystemDlg : public CDialog
{
// Construction
public:
	CCampusNavigationSystemDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CAMPUSNAVIGATIONSYSTEM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnAbout();
private:
	CBitmap m_campusMap;
	Graph m_campus;
	vector<int> path;
public:
	afx_msg void OnCstartpoint();
	afx_msg void OnCendpoint();
	afx_msg void OnClickedBtnCalRoute();

private:
	CComboBox m_CmbStart;
	CComboBox m_CmbEnding;
	CPoint m_coordinates[NUM_OF_VERTICES];
	vector<CString> m_locationsName;
	CStatic m_Static5;
	CStatic m_Static1;
	CStatic m_Static2;
	CStatic m_Static3;
	CStatic m_Static4;
	CButton m_BtnCalRoute;
	void printRoute(vector<int> & nodes, CClientDC * dc);
public:
	void clearRoute(vector<int> nodes, CClientDC * dc);
	afx_msg void OnCampusInfo();
	CString m_minRoute;
private:
	CReadOnlyEdit m_editMinLength;
	CReadOnlyEdit m_editMinRoute;
public:
	static string WCharToAnsi(LPCWSTR pwszSrc);
	afx_msg void OnExit();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
private:
	CFont m_Font;
	CMyMenu m_menu;
	CMyStaticText m_staticTexts[NUM_OF_BUILDINGS];
public:
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);	
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDblclkBuilding1();
	afx_msg void OnDblclkBuilding10();
	afx_msg void OnDblclkBuilding11();
	afx_msg void OnDblclkBuilding12();
	afx_msg void OnDblclkBuilding13();
	afx_msg void OnDblclkBuilding14();
	afx_msg void OnDblclkBuilding15();
	afx_msg void OnDblclkBuilding16();
	afx_msg void OnDblclkBuilding17();
	afx_msg void OnDblclkBuilding18();
	afx_msg void OnDblclkBuilding19();
	afx_msg void OnDblclkBuilding2();
	afx_msg void OnDblclkBuilding3();
	afx_msg void OnDblclkBuilding4();
	afx_msg void OnDblclkBuilding5();
	afx_msg void OnDblclkBuilding6();
	afx_msg void OnDblclkBuilding7();
	afx_msg void OnDblclkBuilding8();
	afx_msg void OnDblclkBuilding9();
};
