#include <Application.h>
#include <WndConfig.h>

Application* Application::g_app = nullptr;

Application::Application()
{
	if (g_app) return;
	g_app = this;
	initInstance();
}

HINSTANCE Application::instance()
{
	return g_app->m_inst;
	//return HINSTANCE();
}

void Application::initInstance()
{
	MEMORY_BASIC_INFORMATION memInfo{};
	SIZE_T res = VirtualQuery(0, &memInfo, sizeof(memInfo));
	if (res == ERROR_INVALID_PARAMETER) {
		assert(0);
	}
	m_inst = (HINSTANCE)memInfo.AllocationBase;


}

int Application::exec()
{
	MSG msg{};
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.lParam;
}
