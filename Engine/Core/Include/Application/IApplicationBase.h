#pragma once

#include "Platform/PlatformCommon.h"
#include <memory>
#include <string>

class IApplicationBase{
public:
    static std::unique_ptr<IApplicationBase> CreateApplicationInstance();
    static std::string MakeAppName(const std::string& EngineName);
public:
    IApplicationBase() {}
    virtual ~IApplicationBase() {}
    virtual void Init(/*int32 width, int32 height,const char* title*/) = 0;
	virtual void Tick(const float DeltaTime) = 0;
	virtual void Release() = 0;

    //inline int32 GetWidth() { return -1; }
    //inline int32 GetHeight() { return -1; }
    inline const std::string& GetAppName() { return std::string(); }
};