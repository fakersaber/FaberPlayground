#include "Launch/Launch.h"
#include "Application/IApplicationBase.h"
#include "FaberEngine.h"

#include <windows.h>

#include <memory>

std::unique_ptr<FEngine> FEnginePtr = nullptr;
std::unique_ptr<IApplicationBase> FApplication = nullptr; 

int32 EngineLuncher::EngineInit(int32 Width, int32 Height, const std::string& AppName){
    FEnginePtr->Init(Width, Height, AppName.c_str());
    FApplication->Init();
    return 0;
}

void EngineLuncher::EngineLoop(){
    while (!FEnginePtr->IsRequestEngineExit()) {
        //#TODO: Add Platform Counter
        FEnginePtr->Tick(0.f);
        FApplication->Tick(0.f);
    }
}

void EngineLuncher::EngineExit(){
    //Engine post exit
    FApplication->Release();
    FEnginePtr->Release();
}

int32 EngineLuncher::GuardedMain(const std::vector<std::string>& CmdLine){
    FEnginePtr = std::make_unique<FEngine>();
    FApplication = IApplicationBase::CreateApplicationInstance();
    
    EngineInit(1400, 900, IApplicationBase::MakeAppName(std::string("Faber")));
    EngineLoop();
    EngineExit();

    return 0;
}
