#pragma once
#include "afxwin.h"
class CMyMenu :	public CMenu {
public:
	CMyMenu();
	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	void ChangeMeuItem(CMenu * pMenu);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual ~CMyMenu();
};

