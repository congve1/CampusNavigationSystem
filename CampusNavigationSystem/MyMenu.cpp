#include "stdafx.h"
#include "MyMenu.h"


CMyMenu::CMyMenu()
{
}


CMyMenu::~CMyMenu()
{
}
void CMyMenu::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	lpMeasureItemStruct->itemHeight = 27;//���
	lpMeasureItemStruct->itemWidth = 200;//���
}
void CMyMenu::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CRect rect = lpDrawItemStruct->rcItem;//rcItem�ƶ��˱����Ƶľ�������
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);//��lpDrawItemStruct�ṹ���е�hDc��dc��
	dc.FillSolidRect(rect, RGB(240, 240, 240));
	CFont font;
	font.CreatePointFont(140, _T("΢���ź�"));//��������
	dc.SelectObject(&font);
	CString * pText = (CString *)lpDrawItemStruct->itemData;
	if (lpDrawItemStruct->itemState & ODS_SELECTED) {
		//�˵���ѡ��
		dc.FillSolidRect(rect, RGB(80, 89, 202));		
	}
	dc.SetTextColor(RGB(213, 25, 0));//�����ı���ɫ
	dc.DrawText(*pText, rect, DT_VCENTER | DT_CENTER | DT_SINGLELINE);//���û��Ʒ�ʽ
	dc.Detach();

}
void CMyMenu::ChangeMeuItem(CMenu * pMenu)
{
	int itemCount = pMenu->GetMenuItemCount();
	for (int i = 0; i < itemCount; i++) {
		CString * pText = new CString;//
		UINT itemID = pMenu->GetMenuItemID(i);//��ȡ�˵���ID
		pMenu->GetMenuStringW(i, *pText, MF_BYPOSITION);//��ȡ�˵��ı�
		pMenu->ModifyMenu(i, MF_OWNERDRAW | MF_BYPOSITION | MF_STRING, itemID,(LPCTSTR)pText);
		if (itemID == -1) {
			//�����һ������ʽ�˵�
			ChangeMeuItem(pMenu->GetSubMenu(i));
		}
		/*
			������ÿ���˵������MF����OWNERDRAW���ԣ���Ȼ�Ӳ���WM_MEASUREITEM��WM_DRAWITEM��Ϣ
		*/
	}
	
}