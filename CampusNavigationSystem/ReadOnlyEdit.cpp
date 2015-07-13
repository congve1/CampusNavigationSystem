// ReadOnlyEdit.cpp : implementation file
//

#include "stdafx.h"
#include "CampusNavigationSystem.h"
#include "ReadOnlyEdit.h"


// CReadOnlyEdit

IMPLEMENT_DYNAMIC(CReadOnlyEdit, CEdit)

CReadOnlyEdit::CReadOnlyEdit()
{

}

CReadOnlyEdit::~CReadOnlyEdit()
{
}


BEGIN_MESSAGE_MAP(CReadOnlyEdit, CEdit)
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()



// CReadOnlyEdit message handlers




void CReadOnlyEdit::OnSetFocus(CWnd* pOldWnd)
{
	pOldWnd->SetFocus();
	//CEdit::OnSetFocus(pOldWnd);
	// TODO: Add your message handler code here
}
