#pragma once


// CMyPictureControl

class CMyPictureControl : public CStatic
{
	DECLARE_DYNAMIC(CMyPictureControl)

public:
	CMyPictureControl();
	virtual ~CMyPictureControl();

protected:
	DECLARE_MESSAGE_MAP()
public:
	void setImage(UINT resID,CRect & rect);
protected:
	CBitmap m_bitMap;
	CRect m_rect;
	afx_msg void OnPaint();
};


