#include "Wnd.h"
#include <WndConfig.h>
#include <iostream>

Wnd::Wnd(Wnd* parent, int x, int y, int w, int h, LPCSTR text)
	: m_parent(parent), WndObject()
{
	
}

HWND Wnd::create(WndCreateInfo& info)
{
	bool bRegistedClass = false;
	WNDCLASSEX wc{};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpszClassName = info.lpChClass;
	wc.hInstance = GetModuleHandle(NULL);
	if (!GetClassInfoEx(wc.hInstance, wc.lpszClassName, &wc)) {
		LOG::message("%s is not registed add now ...", wc.lpszClassName);
	}
	else {
		LOG::message("%s is registed already", wc.lpszClassName);
		bRegistedClass = true;
	}
	preCreateClass(wc);
	RegisterClassEx(&wc);

	HWND hwndParent = m_parent ? m_parent->m_hwnd : nullptr;
	DWORD style = info.dwStyle;
	if (hwndParent) {
		style |= WS_CHILD; style &= WS_POPUP;
	}
	else {
		style &= ~WS_CHILD; style |= WS_POPUP;
	}
	CREATESTRUCT cs{};
	cs.dwExStyle = NULL;
	cs.style = style;
	cs.hInstance = wc.hInstance;
	cs.hwndParent = hwndParent;
	cs.lpszClass = wc.lpszClassName;
	cs.lpszName = info.lpChName;
	cs.x = info.x;
	cs.y = info.y;
	cs.cx = info.cx;
	cs.cy = info.cy;
	cs.hMenu = (HMENU)0;
	cs.lpCreateParams = this;
	preCreateWnd(cs);
	
	m_hwnd = CreateWindowEx(cs.dwExStyle, cs.lpszClass, cs.lpszName, cs.style,
		cs.x, cs.y, cs.cx, cs.cy, 
		cs.hwndParent, cs.hMenu, cs.hInstance, cs.lpCreateParams);
	
	return m_hwnd;
}

void Wnd::preCreateClass(WNDCLASSEX & wc)
{
}

void Wnd::preCreateWnd(CREATESTRUCT & cs)
{
}
