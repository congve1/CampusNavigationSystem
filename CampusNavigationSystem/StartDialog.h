#pragma once
#include <vector>
using std::vector;
// CStartDialog dialog

class CStartDialog : public CDialog
{
	DECLARE_DYNAMIC(CStartDialog)

public:
	CStartDialog(CWnd* pParent = NULL); 
	CStartDialog(CWnd * pParent, vector<CString> & locNames);// standard constructor
	virtual ~CStartDialog();

// Dialog Data
	enum { IDD = IDD_SET_START_POINT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	vector<CString> m_locationNames;
	virtual void OnOK();
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedBtnOk();
	afx_msg void OnClickedBtnCancel();
};
