#pragma once

#include "PlatformCommon.h"
#include <memory>

class IPlatformWindow {
public:
	IPlatformWindow() {};
	virtual ~IPlatformWindow() {}
	virtual void Init(int32 width, int32 height, const char* title) = 0;
	virtual void Tick(const float DeltaTime) = 0;
	virtual void Release() = 0;
};