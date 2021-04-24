#include "WinWindow.h"

#include <memory>

std::unique_ptr<IPlatformWindow> IPlatformWindow::CreatePlatformWindow() {
	return nullptr;
}


WinWindow::WinWindow()
{
}

WinWindow::~WinWindow()
{
}

void WinWindow::Init(int32 width, int32 height, const char* title)
{
}

void WinWindow::Tick(const float DeltaTime)
{
}

void WinWindow::Release()
{
}
