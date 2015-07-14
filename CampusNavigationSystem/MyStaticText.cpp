// MyStaticText.cpp : implementation file
//

#include "stdafx.h"
#include "CampusNavigationSystem.h"
#include "MyStaticText.h"
#include "CampusInfoDialog.h"

// CMyStaticText

IMPLEMENT_DYNAMIC(CMyStaticText, CStatic)

CMyStaticText::CMyStaticText()
{

}

CMyStaticText::~CMyStaticText()
{
}


BEGIN_MESSAGE_MAP(CMyStaticText, CStatic)
END_MESSAGE_MAP()

void CMyStaticText::SetFont()
{
	m_Font.CreatePointFont(90, _T("Î¢ÈíÑÅºÚ"));
	CStatic::SetFont(&m_Font);
}
void CMyStaticText::OpenDialog(vector<CString> & names, int nIndex)
{
	CCampusInfoDialog dlg(NULL,names,nIndex);
	dlg.DoModal();
}

// CMyStaticText message handlers


