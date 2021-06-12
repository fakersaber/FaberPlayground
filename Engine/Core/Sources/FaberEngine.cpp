#include "FaberEngine.h"
#include "Platform/IPlatformApplication.h"
#include "Platform/IPlatformWindow.h"

FEngine::FEngine()
	: bIsExit(false)
{
	ApplicationPtr = IPlatformAppication::CreatePlatformApp();
	ApplicationWindowPtr = IPlatformWindow::CreatePlatformWindow();
}

FEngine::~FEngine(){
	ApplicationPtr.reset();
	ApplicationWindowPtr.reset();
}

void FEngine::Init(/*const std::vector<std::string>& cmdLine, */int32 width, int32 height, const char* title){
	ApplicationPtr->Init(width, height, title);
	ApplicationWindowPtr->Init(width, height, title);
}

void FEngine::Tick(const float DeltaTime) {
	ApplicationPtr->Tick(DeltaTime); //平台App管理逻辑,例如输入输出,程序退出,资源管理等
	ApplicationWindowPtr->Tick(DeltaTime);//窗口前端接收消息并转发

	//Set Exit Status
	RequestExit(WindowExit);
}

void FEngine::Release() {
	ApplicationPtr->Release();
	ApplicationWindowPtr->Release();
}

bool FEngine::IsRequestExit() const{
	return bIsExit;
}

void FEngine::RequestExit(const bool ExitStatus){
	bIsExit = ExitStatus;
}