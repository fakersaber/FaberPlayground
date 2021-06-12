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
	//构造函数与析构函数申请释放成员内存
	FEngine();
	~FEngine();

	//Init与Release函数管理资源
	void Init(/*const std::vector<std::string>& cmdLine, */int32 width, int32 height, const char* title);
	void Tick(const float DeltaTime);
	void Release();
	bool IsRequestExit() const;
	void RequestExit(const bool ExitStatus);
private:
	//[Resources Manager]
	bool bIsExit;
	std::unique_ptr<IPlatformAppication> ApplicationPtr;
	std::unique_ptr<IPlatformWindow> ApplicationWindowPtr;
};