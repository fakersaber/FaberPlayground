#include "Platform/Windows/WinWindow.h"
#include "Platform/Windows/WinApplication.h"
#include <memory>
#include <cassert>

static constexpr char* AppWindowClass = "FaberWindow";

std::unique_ptr<IPlatformWindow> IPlatformWindow::CreatePlatformWindow() {
	return std::make_unique<WinWindow>();
}

WinWindow::WinWindow(){

}

WinWindow::~WinWindow(){

}

void WinWindow::Init(int32 width, int32 height, const char* title){
	assert(WinApplication::AppHInstance != nullptr);
	Width = width;
	Height = height;
	WindowTitle = std::string(title);

	WNDCLASSEX WindowInfo = { 0 };
	WindowInfo.cbSize = sizeof(WNDCLASSEX);
	WindowInfo.hInstance = WinApplication::AppHInstance; /*GetModuleHandle(nullptr);*/ //使用DLL时句柄不是应用程序而是链接库
	WindowInfo.hCursor = LoadCursor(nullptr, IDC_ARROW); //标准的箭头
	WindowInfo.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1); //+1 got diffrent color with the color of mune
	WindowInfo.style = CS_HREDRAW | CS_VREDRAW;
	WindowInfo.lpfnWndProc = WndProc;
	WindowInfo.lpszClassName = AppWindowClass
	RegisterClassEx(&WindowInfo);


	RECT rc = { 0, 0, width, height };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, false); //WS_OVERLAPPEDWINDOW可以创建一个拥有各种窗口风格的窗体，包括标题，系统菜单，边框，最小化和最大化按钮等
	WindowHandle = CreateWindowEx(
		WS_EX_APPWINDOW, //任务栏?
		WindowInfo.lpszClassName, 
		WindowTitle.c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		rc.right - rc.left, 
		rc.bottom - rc.top, 
		nullptr, 
		nullptr, 
		WindowInfo.hInstance, 
		nullptr);

}

void WinWindow::Tick(const float DeltaTime){

}

void WinWindow::Release(){

}
