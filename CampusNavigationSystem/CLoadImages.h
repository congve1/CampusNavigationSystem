#pragma once
#include "stdafx.h"
class CLoadImages {
public:
	CLoadImages();
	static bool LoadImageFromResource(IN CImage * pImage,
									  IN UINT nResId,
									  IN LPCTSTR lpType);
	~CLoadImages();
};

