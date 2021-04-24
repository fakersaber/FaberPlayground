#pragma once

#include "Platform/IPlatformWindow.h"

class WinWindow : public IPlatformWindow {
public:
	WinWindow();
	virtual ~WinWindow();
	virtual void Init(int32 width, int32 height, const char* title) override;
	virtual void Tick(const float DeltaTime) override;
	virtual void Release() override;
};