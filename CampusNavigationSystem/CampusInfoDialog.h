#pragma once
#include <vector>
#include "afxcmn.h"
using namespace std;
// CCampusInfoDialog dialog

class CCampusInfoDialog : public CDialog
{
	DECLARE_DYNAMIC(CCampusInfoDialog)

public:
	CCampusInfoDialog(CWnd* pParent = NULL);   
	CCampusInfoDialog(CWnd * pParent, vector<CString> & locNames);
	virtual ~CCampusInfoDialog();

// Dialog Data
	enum { IDD = IDD_CAMPUS_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	
	DECLARE_MESSAGE_MAP()
private:
	vector<CString> m_locationNames;
	virtual void OnOK();
public:
	afx_msg void OnClickedBtnExit();
private:
	CTabCtrl m_tabControl;
	CDialog dlg;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTabCampusInfo(NMHDR *pNMHDR, LRESULT *pResult);
};
