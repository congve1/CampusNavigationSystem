// ZoomPicDialog.cpp : implementation file
//

#include "stdafx.h"
#include "CampusNavigationSystem.h"
#include "ZoomPicDialog.h"
#include "afxdialogex.h"


// CZoomPicDialog dialog

IMPLEMENT_DYNAMIC(CZoomPicDialog, CDialog)

CZoomPicDialog::CZoomPicDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CZoomPicDialog::IDD, pParent)
{

}

CZoomPicDialog::~CZoomPicDialog()
{
}

void CZoomPicDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CZoomPicDialog, CDialog)
	
	ON_BN_CLICKED(IDC_BTN_ENLARGE, &CZoomPicDialog::OnClickedBtnEnlarge)
	ON_BN_CLICKED(IDC_BTN_SHORTEN, &CZoomPicDialog::OnClickedBtnShorten)
END_MESSAGE_MAP()


// CZoomPicDialog message handlers


BOOL CZoomPicDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	ModifyStyle(WS_THICKFRAME, 0, SWP_FRAMECHANGED | SWP_DRAWFRAME);
	CRect rect;
	GetClientRect(rect);//获取对话框窗口尺寸
	CRect btnRect;
	GetDlgItem(IDC_BTN_ENLARGE)->GetClientRect(btnRect);
	CRuntimeClass * pViewClass = RUNTIME_CLASS(CMyScrollView);//获得CMyScrollView类的一个运行时类结构
	CCreateContext * pContext;//建立视图时，此结构中的值用于连接构成文档的组建和文档数据的视图
	pContext = new CCreateContext;
	pContext->m_pCurrentDoc = NULL;//将在其上创建视图的文档,不需要或者未知时可设为NULL
	pContext->m_pCurrentFrame = NULL;//待创建视图所依据的框架窗口，不需要或者未知时可设为NULL
	pContext->m_pLastView = NULL;//待创建视图所依据的原始视图，不需要或者未知时可设为NULL
	pContext->m_pNewDocTemplate = NULL;//待创建的新MDI框架窗口的文档模板,不需要或者未知时可设为NULL
	pContext->m_pNewViewClass = pViewClass;//待创建视图的CRuntimeClass,不需要或者未知时可设为NULL
	CWnd *pWnd = NULL;
	/*DYnAMIC_DOWNCAST(class,pointer):如果pointer指针所指向的对象是class类型的，就返回这个指针;否则返回NULL*/
	pWnd = DYNAMIC_DOWNCAST(CWnd, pViewClass->CreateObject());
	pWnd->Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, 0, pContext);
	delete pContext;
	m_picScrollView =(DYNAMIC_DOWNCAST(CMyScrollView, pWnd));
	m_picScrollView->SetScrollSizes(MM_TEXT, CSize(rect.Width() - 20, rect.bottom - btnRect.bottom));//设置视图的滚动条范围
	m_picScrollView->MoveWindow(rect.left + 10 , rect.top + btnRect.bottom + 30, rect.Width() - 20, rect.bottom - btnRect.bottom- 30, TRUE);//设置视图位置和大小
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}



void CZoomPicDialog::OnClickedBtnEnlarge()
{
	// TODO: Add your control notification handler code here
	m_picScrollView->enlarge();
}


void CZoomPicDialog::OnClickedBtnShorten()
{
	// TODO: Add your control notification handler code here
	m_picScrollView->shrink();
}
