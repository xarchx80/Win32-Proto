#pragma once

#if(_MSC_VER >= 1915)
#define no_init_all deprecated
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif // WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>

#define SAFE_DELETE(x) if(x)		{ delete x; x= nullptr;}
#define SAFE_DELETE_WND(x) if(x)	{ DestroyWindow(x); x = nullptr;}
#define SAFE_DELETE_OBJ(x) if(x)	{ DeleteObject(x); x = nullptr;}

#include <assert.h>
#include <string>

namespace LOG {
	void message(LPCSTR code, ...);
}
