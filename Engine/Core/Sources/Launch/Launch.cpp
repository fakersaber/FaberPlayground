#include "Launch/Launch.h"
#include "FaberEngine.h"

#include <memory>

std::unique_ptr<FEngine> FEnginePtr = nullptr;

int32 EngineLuncher::EngineInit(){
    return 0;
}

void EngineLuncher::EngineLoop(){
    
}

void EngineLuncher::EngineExit(){

}

int32 EngineLuncher::GuardedMain(const std::vector<std::string>& cmdLine){
    FEnginePtr = std::make_unique<FEngine>();
}
