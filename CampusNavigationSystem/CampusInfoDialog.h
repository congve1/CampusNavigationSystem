#pragma once
#include <vector>
#include "afxcmn.h"
#include "InfoDialog.h"
using namespace std;
// CCampusInfoDialog dialog
const int NUM_OF_BUILDINGS = 19;
class CCampusInfoDialog : public CDialog
{
	DECLARE_DYNAMIC(CCampusInfoDialog)

public:
	CCampusInfoDialog(CWnd* pParent = NULL);   
	CCampusInfoDialog(CWnd * pParent, vector<CString> & locNames,int nIndex = 0);
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
	CInfoDialog m_dialogs[NUM_OF_BUILDINGS];
	CString m_buildingsInfo[NUM_OF_BUILDINGS];
	UINT m_picturesID[NUM_OF_BUILDINGS];
	int m_StartPage;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTabCampusInfo(NMHDR *pNMHDR, LRESULT *pResult);
private:
	void showTab(int nIndex);
};
