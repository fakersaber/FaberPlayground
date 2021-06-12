#include <memory>
#include <cassert>
#include "Platform/Windows/WinWindow.h"
#include "Platform/Windows/WinApplication.h"

static constexpr char* AppWindowClass = "FaberWindow";

WinWindow::WinWindow()
	: IPlatformWindow()
	, Width(0)
	, Height(0)
	, WindowHandle(nullptr)
	, WindowTitle(std::string("Error Window Title"))
{

}

WinWindow::~WinWindow(){

}

void WinWindow::Init(int32 width, int32 height, const char* title){
	HINSTANCE AppHInstance = WinApplication::GetWinApplicationHINSTANCE();
	assert(AppHInstance != nullptr);
	Width = width;
	Height = height;
	WindowTitle = std::string(title);

	WNDCLASSEX WindowInfo = { 0 };
	WindowInfo.cbSize = sizeof(WNDCLASSEX);
	WindowInfo.hInstance = AppHInstance; /*GetModuleHandle(nullptr);*/ //When using a DLL, the handle is not an application but a link library
	WindowInfo.hCursor = LoadCursor(nullptr, IDC_ARROW); //Standard arrow
	WindowInfo.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1); //+1 got diffrent color with the color of mune
	WindowInfo.style = CS_HREDRAW | CS_VREDRAW;
	WindowInfo.lpfnWndProc = WinWindow::WndProc;
	WindowInfo.lpszClassName = AppWindowClass;
	RegisterClassEx(&WindowInfo);

	RECT rc = { 0, 0, width, height };
	//WS_OVERLAPPEDWINDOW can create a window with various window styles, including title, system menu, border, minimize and maximize buttons, etc.
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, false); 
	WindowHandle = CreateWindowEx(
		WS_EX_APPWINDOW, //mission Board
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

	ShowWindow(WindowHandle, SW_SHOW);
}

void WinWindow::Tick(const float DeltaTime){
	MSG msg = {};
	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void WinWindow::Release(){

}

LRESULT WinWindow::WndProc(HWND Hwnd, uint32 Msg, WPARAM wParam, LPARAM lParam)
{
	//See https://stackoverflow.com/questions/3155782/what-is-the-difference-between-wm-quit-wm-close-and-wm-destroy-in-a-windows-pr
	switch (Msg)
	{
		case WM_CLOSE: {
			//The default platform application is only one, and the window handle is passed in to handle the multi-window situation?
			WinApplication::GetWinApplicationInstance()->OnWindowClose();
			return 0;
		}

		case WM_DESTROY:{
			PostQuitMessage(0);
			return 0;
		}
	}
	return DefWindowProc(Hwnd, Msg, wParam, lParam);
}
