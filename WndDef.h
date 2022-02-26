#pragma once

typedef char			CHAR;
typedef short			SHORT;
typedef long			LONG;
typedef unsigned long	DWORD;
typedef int				BOOL;
typedef unsigned char	BYTE;
typedef unsigned short	WORD;
typedef float			FLOAT;
typedef int				INT;
typedef unsigned int	UINT;
typedef UINT			WPARAM;
typedef LONG			LPARAM;
typedef LONG			LRESULT;
typedef char*			LPSTR;
typedef const char*		LPCSTR;

#define WINAPI		__stdcall
#define CALLBACK	__stdcall
#define APIENTRY	WINAPI

typedef void *HANDLE;
typedef void *PVOID;

struct	HWND__;
typedef HWND__*			HWND;
struct	HINSTANCE__;
typedef HINSTANCE__*	HINSTANCE;
struct	HDC__;
typedef	HDC__*			HDC;

typedef struct tagWNDCLASSEXA WNDCLASSEX;
typedef struct tagCREATESTRUCTA CREATESTRUCT;

typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
//#include <minwindef.h>

class Wnd;
class WndObject;