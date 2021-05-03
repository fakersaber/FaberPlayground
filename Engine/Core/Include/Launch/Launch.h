#pragma once

#include "Platform/PlatformCommon.h"

#include <string>
#include <vector>

struct EngineLuncher{
    static int32 GuardedMain(const std::vector<std::string>& cmdLine);
    static int32 EngineInit(int32 width, int32 height, const std::string& AppName);
    static void EngineLoop();
    static void EngineExit();
};

