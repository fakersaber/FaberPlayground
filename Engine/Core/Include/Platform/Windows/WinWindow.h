#pragma once

#include "Platform/IPlatformWindow.h"
#include <windows.h>
#include <string>

class WinWindow : public IPlatformWindow {
public:
	WinWindow();
	virtual ~WinWindow();
	virtual void Init(int32 width, int32 height, const char* title) override;
	virtual void Tick(const float DeltaTime) override;
	virtual void Release() override;

private:
	int32 Width;
	int32 Height;
	HWND WindowHandle;
	std::string WindowTitle;
};