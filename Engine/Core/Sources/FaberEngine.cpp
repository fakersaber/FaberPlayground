#include "FaberEngine.h"
#include "Platform/IPlatformApplication.h"
#include "Platform/IPlatformWindow.h"

FEngine::FEngine()
{
	ApplicationPtr = IPlatformAppication::CreatePlatformApp();
	ApplicationWindowPtr = IPlatformWindow::CreatePlatformWindow();
}

FEngine::~FEngine(){
	ApplicationPtr.reset();
	ApplicationWindowPtr.reset();
}

void FEngine::Init(const std::vector<std::string>& cmdLine, int32 width, int32 height, const char* title){
	ApplicationPtr->Init(width, height, title);
	ApplicationWindowPtr->Init(width, height, title);
}

void FEngine::Release(){
	ApplicationPtr->Release();
	ApplicationWindowPtr->Release();
}

void FEngine::Tick(const float DeltaTime){

}
