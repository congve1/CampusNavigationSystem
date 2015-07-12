#pragma once
#include <vector>
using std::vector;
// CEndDialog dialog

class CEndDialog : public CDialog
{
	DECLARE_DYNAMIC(CEndDialog)

public:
	CEndDialog(CWnd* pParent = NULL); 
	CEndDialog(CWnd * pParent, vector<CString> & locNames);// standard constructor
	virtual ~CEndDialog();

// Dialog Data
	enum { IDD = IDD_SET_END_POINT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedBtnOk();
	afx_msg void OnClickedBtnCancel();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
private:
	vector<CString> m_locationName;
};
