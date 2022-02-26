#include <Wnd.h>
#include <iostream>
#include <Application.h>

int main(int args, char* argv[])
{
	Application app;
	Wnd window(nullptr, 200, 200, 500, 200, "aaa");
	WndCreateInfo info{ 200,200,500,200,"button","button" };
	window.create(info);
	window.show();

	
	return app.exec();
}