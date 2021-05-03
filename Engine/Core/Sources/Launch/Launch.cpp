#include "Launch/Launch.h"
#include "Application/IApplicationBase.h"
#include "FaberEngine.h"

#include <windows.h>

#include <memory>

std::unique_ptr<FEngine> FEnginePtr = nullptr;
std::unique_ptr<IApplicationBase> FApplication = nullptr; 

int32 EngineLuncher::EngineInit(int32 width, int32 height, const std::string& AppName){
    FEnginePtr->Init(width, height, AppName.c_str());
    FApplication->Init();
    return 0;
}

void EngineLuncher::EngineLoop(){
    
}

void EngineLuncher::EngineExit(){
    FEnginePtr->Release();
    FApplication->Release();
}

int32 EngineLuncher::GuardedMain(const std::vector<std::string>& cmdLine){
    FEnginePtr = std::make_unique<FEngine>();
    FApplication = IApplicationBase::CreateApplicationInstance();
    
    EngineInit(1400, 900, IApplicationBase::MakeAppName(std::string("Faber")));
    EngineLoop();
    EngineExit();

    return 0;
}
