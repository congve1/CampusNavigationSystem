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
	GetClientRect(rect);//��ȡ�Ի��򴰿ڳߴ�
	CRect btnRect;
	GetDlgItem(IDC_BTN_ENLARGE)->GetClientRect(btnRect);
	CRuntimeClass * pViewClass = RUNTIME_CLASS(CMyScrollView);//���CMyScrollView���һ������ʱ��ṹ
	CCreateContext * pContext;//������ͼʱ���˽ṹ�е�ֵ�������ӹ����ĵ����齨���ĵ����ݵ���ͼ
	pContext = new CCreateContext;
	pContext->m_pCurrentDoc = NULL;//�������ϴ�����ͼ���ĵ�,����Ҫ����δ֪ʱ����ΪNULL
	pContext->m_pCurrentFrame = NULL;//��������ͼ�����ݵĿ�ܴ��ڣ�����Ҫ����δ֪ʱ����ΪNULL
	pContext->m_pLastView = NULL;//��������ͼ�����ݵ�ԭʼ��ͼ������Ҫ����δ֪ʱ����ΪNULL
	pContext->m_pNewDocTemplate = NULL;//����������MDI��ܴ��ڵ��ĵ�ģ��,����Ҫ����δ֪ʱ����ΪNULL
	pContext->m_pNewViewClass = pViewClass;//��������ͼ��CRuntimeClass,����Ҫ����δ֪ʱ����ΪNULL
	CWnd *pWnd = NULL;
	/*DYnAMIC_DOWNCAST(class,pointer):���pointerָ����ָ��Ķ�����class���͵ģ��ͷ������ָ��;���򷵻�NULL*/
	pWnd = DYNAMIC_DOWNCAST(CWnd, pViewClass->CreateObject());
	pWnd->Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, 0, pContext);
	delete pContext;
	m_picScrollView =(DYNAMIC_DOWNCAST(CMyScrollView, pWnd));
	m_picScrollView->SetScrollSizes(MM_TEXT, CSize(rect.Width() - 20, rect.bottom - btnRect.bottom));//������ͼ�Ĺ�������Χ
	m_picScrollView->MoveWindow(rect.left + 10 , rect.top + btnRect.bottom + 30, rect.Width() - 20, rect.bottom - btnRect.bottom- 30, TRUE);//������ͼλ�úʹ�С
	
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
