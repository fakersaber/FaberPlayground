#pragma once

#include "Platform/IPlatformWindow.h"
#include <windows.h>
#include <string>

class WinApplication;

class WinWindow : public IPlatformWindow {
public:
	WinWindow();
	virtual ~WinWindow();
	virtual void Init(int32 InWidth, int32 InHeight, const char* Title) override;
	virtual void Tick(const float DeltaTime) override;
	virtual void Release() override;
	static LRESULT CALLBACK WndProc(HWND Hwnd, uint32 Msg, WPARAM wParam, LPARAM lParam);
private:
	//[Resources Ref]
	int32 Width;
	int32 Height;
	HWND WindowHandle;
	std::string WindowTitle;
};