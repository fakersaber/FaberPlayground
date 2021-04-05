#pragma once

#include "Platform/IPlatformApplication.h"

class WinApplication : public IPlatformAppication {
public:
	WinApplication();
	virtual ~WinApplication();
	virtual void Init(int32 width, int32 height, const char* title) override;
	virtual void Tick(const float DeltaTime) override;
	virtual void Release() override;
};