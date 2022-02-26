#include <WndObject.h>
#include <WndConfig.h>

WndObject::WndObject()
	: m_hwnd(nullptr)
{
}

HWND WndObject::getHwnd() const
{
	if (::IsWindow(m_hwnd))
		return m_hwnd;
	return nullptr;
}

void WndObject::setHwnd(HWND hwnd)
{
	m_hwnd = hwnd;
}

void WndObject::show()
{
	assert(IsWindow(m_hwnd));
	ShowWindow(m_hwnd, SW_SHOW);
}

void WndObject::hide()
{
	assert(IsWindow(m_hwnd));
	ShowWindow(m_hwnd, SW_HIDE);
}

LPCSTR WndObject::getText() const
{
	assert(::IsWindow(m_hwnd));
	static std::basic_string<TCHAR> chText;
	chText.clear();
	int len = GetWindowTextLength(m_hwnd) + 1;
	chText.reserve(len);
	GetWindowText(m_hwnd, (LPSTR)chText.data(), len);
	return chText.c_str();
}
