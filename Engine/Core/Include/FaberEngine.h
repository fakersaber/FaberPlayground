#pragma once

#include "Platform/PlatformCommon.h"
#include <vector>
#include <string>

class IPlatformAppication;

//Created By Launcher
class FEngine {
public:
	static FEngine* Get() { return GEnginePtr; }

private:
	static FEngine* GEnginePtr;

public:
	FEngine();
	~FEngine();
	void Init(const std::vector<std::string>& cmdLine, int32 width, int32 height, const char* title);
	void Tick(const float DeltaTime);
	void Release();

private:
	//[Resources Ref]
	IPlatformAppication* ApplicationPtr;
};