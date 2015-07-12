
// CampusNavigationSystemDlg.h : header file
//

#pragma once
#include "Graph.h"
#include "afxwin.h"

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
	void printRoute(vector<int> & nodes, CClientDC * dc);
public:
	void clearRoute(vector<int> nodes, CClientDC * dc);
};
