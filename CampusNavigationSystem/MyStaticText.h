#pragma once
// CMyStaticText
#include <vector>
using std::vector;
class CMyStaticText : public CStatic
{
	DECLARE_DYNAMIC(CMyStaticText)

public:
	CMyStaticText();
	virtual ~CMyStaticText();
	void SetFont();
	void OpenDialog(vector<CString> & names,int nIndex);
protected:
	DECLARE_MESSAGE_MAP()
private:
	CFont m_Font;
};


