#include "FaberEngine.h"
#include "Platform/IPlatformApplication.h"
#include "Platform/IPlatformWindow.h"

FEngine::FEngine()
	: bIsExit(false)
{
	ApplicationPtr = IPlatformAppication::CreatePlatformApp();
}

FEngine::~FEngine(){
	ApplicationPtr.reset();
}

void FEngine::Init(/*const std::vector<std::string>& cmdLine, */int32 Width, int32 Height, const char* Title){
	ApplicationPtr->Init(Width, Height, Title);
}

void FEngine::Tick(const float DeltaTime) {
	const bool bApplicationExit = ApplicationPtr->Tick(DeltaTime); //Platform App management logic, such as input and output, program exit, resource management, etc.

	//Set Exit Status
	RequestEngineExit(bApplicationExit);
}

void FEngine::Release() {
	ApplicationPtr->Release();
}

bool FEngine::IsRequestEngineExit() const{
	return bIsExit;
}

void FEngine::RequestEngineExit(const bool ExitStatus){
	bIsExit = ExitStatus;
}