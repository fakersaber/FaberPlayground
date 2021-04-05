#pragma once

#include "PlatformCommon.h"

class IPlatformWindow;

class IPlatformAppication {
public:
    static IPlatformAppication* CreatePlatformApp();

public:
	IPlatformAppication() : WindowPtr(nullptr) { };
	virtual ~IPlatformAppication() {}
    virtual void Init(int32 width, int32 height, const char* title) = 0;
    virtual void Tick(const float DeltaTime) = 0;
    virtual void Release() = 0;

protected:
    IPlatformWindow* WindowPtr;
};

//#if 1
//    #define DEFINE_APPLICATION_MAIN(appClass)                     \
//    extern int WindowsMain(int argc, char** argv);                \
//    int main(int argc, char** argv)                               \
//	{                                                             \
//        return WindowsMain(argc, argv);                           \
//	}
//#endif
