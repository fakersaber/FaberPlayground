#include "FaberEngine.h"
#include "Platform/IPlatformApplication.h"

FEngine* FEngine::GEnginePtr = nullptr;

FEngine::FEngine()
	: ApplicationPtr(nullptr)
{

}

FEngine::~FEngine(){

}

void FEngine::Init(const std::vector<std::string>& cmdLine, int32 width, int32 height, const char* title){
	ApplicationPtr = IPlatformAppication::CreatePlatformApp();
}

void FEngine::Release(){
	ApplicationPtr->Release();
	delete ApplicationPtr;
}

void FEngine::Tick(const float DeltaTime){

}
