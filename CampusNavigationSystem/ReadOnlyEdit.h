#pragma once


// CReadOnlyEdit

class CReadOnlyEdit : public CEdit
{
	DECLARE_DYNAMIC(CReadOnlyEdit)

public:
	CReadOnlyEdit();
	virtual ~CReadOnlyEdit();
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSetFocus(CWnd* pOldWnd);
private:
	CFont m_Font;
};


