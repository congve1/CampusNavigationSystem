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
	lpMeasureItemStruct->itemHeight = 27;//项高
	lpMeasureItemStruct->itemWidth = 200;//项宽
}
void CMyMenu::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CRect rect = lpDrawItemStruct->rcItem;//rcItem制定了被绘制的矩形区域
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);//将lpDrawItemStruct结构体中的hDc与dc绑定
	dc.FillSolidRect(rect, RGB(240, 240, 240));
	CFont font;
	font.CreatePointFont(140, _T("微软雅黑"));//创建字体
	dc.SelectObject(&font);
	CString * pText = (CString *)lpDrawItemStruct->itemData;
	if (lpDrawItemStruct->itemState & ODS_SELECTED) {
		//菜单背选中
		dc.FillSolidRect(rect, RGB(80, 89, 202));		
	}
	dc.SetTextColor(RGB(213, 25, 0));//设置文本颜色
	dc.DrawText(*pText, rect, DT_VCENTER | DT_CENTER | DT_SINGLELINE);//设置绘制方式
	dc.Detach();

}
void CMyMenu::ChangeMeuItem(CMenu * pMenu)
{
	int itemCount = pMenu->GetMenuItemCount();
	for (int i = 0; i < itemCount; i++) {
		CString * pText = new CString;//
		UINT itemID = pMenu->GetMenuItemID(i);//获取菜单项ID
		pMenu->GetMenuStringW(i, *pText, MF_BYPOSITION);//获取菜单文本
		pMenu->ModifyMenu(i, MF_OWNERDRAW | MF_BYPOSITION | MF_STRING, itemID,(LPCTSTR)pText);
		if (itemID == -1) {
			//如果是一个弹出式菜单
			ChangeMeuItem(pMenu->GetSubMenu(i));
		}
		/*
			必须让每个菜单项具有MF——OWNERDRAW属性，不然接不到WM_MEASUREITEM和WM_DRAWITEM消息
		*/
	}
	
}