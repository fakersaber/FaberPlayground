#pragma once

#include "Platform/IPlatformApplication.h"
#include <windows.h>

struct WindowsMessageHandler : public IMessageHandler {
	WindowsMessageHandler();
	virtual ~WindowsMessageHandler();
	virtual void OnWindowClose() override;
};

class WinApplication : public IPlatformAppication {
public:
	static HINSTANCE AppHInstance;

public:
	WinApplication();
	virtual ~WinApplication();
	virtual void Init(int32 width, int32 height, const char* title) override;
	virtual void Tick(const float DeltaTime) override;
	virtual void Release() override;
};