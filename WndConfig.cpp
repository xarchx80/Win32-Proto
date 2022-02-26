#include <WndConfig.h>
#include <iostream>

void LOG::message(LPCSTR code, ...)
{
	TCHAR buf[512];
	va_list args;
	va_start(args, code);
	vsprintf(buf, code, args);
	va_end(args);
	std::cout << buf << std::endl;
}
