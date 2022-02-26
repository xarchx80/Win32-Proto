#pragma once
#include <WndDef.h>

class WndObject
{
public:
	WndObject();
	HWND getHwnd() const;
	void setHwnd(HWND hwnd);
	void show();
	void hide();
	LPCSTR getText() const;
	HWND m_hwnd;
};

