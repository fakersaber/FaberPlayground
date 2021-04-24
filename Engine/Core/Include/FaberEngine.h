#pragma once

#include "Platform/PlatformCommon.h"

#include <vector>
#include <string>
#include <memory>

class IPlatformAppication;
class IPlatformWindow;

//Created By Launcher
class FEngine {
public:
	FEngine();
	~FEngine();
	void Init(const std::vector<std::string>& cmdLine, int32 width, int32 height, const char* title);
	void Tick(const float DeltaTime);
	void Release();

private:
	//[Resources Ref]
	std::unique_ptr<IPlatformAppication> ApplicationPtr;
	std::unique_ptr<IPlatformWindow> ApplicationWindowPtr;
};