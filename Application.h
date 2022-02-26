#pragma once
#include <WndDef.h>

#define App		Application::g_app

class Application
{
public:
	Application();
	Application(const Application& rhs) = delete;
	Application& operator=(const Application& rhs) = delete;
	static HINSTANCE instance();
	int exec();
protected:


	void initInstance();
	
private:
	static Application* g_app;
	HINSTANCE m_inst;
};

