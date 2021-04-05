#include "WinApplication.h"

#include <memory>
#include <cassert>
#include <windows.h>

static WinApplication* GCurrentPlatformApp = nullptr;

IPlatformAppication* IPlatformAppication::CreatePlatformApp() {
	GCurrentPlatformApp = new WinApplication();
	return static_cast<IPlatformAppication*>(GCurrentPlatformApp);
}


WinApplication::WinApplication()
	:IPlatformAppication()
{
	//WNDCLASSEX wc;
	//std::memset(&wc, 0, sizeof(WNDCLASSEX));
	//wc.cbSize = sizeof(WNDCLASSEX);
	//wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	//wc.lpfnWndProc = AppWndProc;
	//wc.hInstance = g_HInstance;
	//wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	//wc.lpszClassName = WinWindow::AppWindowClass;
	//RegisterClassEx(&wc);
}

WinApplication::~WinApplication(){
	if (WindowPtr != nullptr) {
		//#todo: Log system
		assert(false);
	}
}

void WinApplication::Init(int32 width, int32 height, const char* title){

}

void WinApplication::Tick(const float DeltaTime){

}

void WinApplication::Release(){
	if (WindowPtr != nullptr) {
		/*WindowPtr->Release();*/
		WindowPtr = nullptr;
	}
}
