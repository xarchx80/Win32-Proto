#pragma once

#include <WndObject.h>

#define WT_STANDARD
#define WT_SUBCLASS
#define WT_SUPERCLASS

typedef struct tagWNDCREATINFO{
	LONG	x;
	LONG	y;
	LONG	cx;
	LONG	cy;
	LPCSTR	lpChName;
	LPCSTR	lpChClass;
	DWORD	dwStyle;
	DWORD   dwWndType;
}WndCreateInfo;

class Wnd : public WndObject
{
public:
	Wnd(Wnd* parent, int x, int y, int w, int h, LPCSTR text);

	HWND create(WndCreateInfo& info);
	virtual void preCreateClass(WNDCLASSEX& wc);
	virtual void preCreateWnd(CREATESTRUCT& cs);
	Wnd* m_parent;
	//HWND m_hwnd;
	WNDPROC m_preWndProc;
};

#include <unordered_map>

class WndCache
{
public:
	WndCache() {};

	//static std::unordered_map<HWND, Wnd*> m_wndCache;
};

