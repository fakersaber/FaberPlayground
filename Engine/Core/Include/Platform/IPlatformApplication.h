#pragma once

#include "PlatformCommon.h"
#include <memory>

struct IMessageHandler {
    virtual void OnWindowClose() = 0;
};

class IPlatformAppication {
public:
    static std::unique_ptr<IPlatformAppication> CreatePlatformApp();

public:
    IPlatformAppication()
        : MessageHandler(nullptr)
    {

    }
    virtual ~IPlatformAppication() {}
    virtual void Init(int32 width, int32 height, const char* title) = 0;
    virtual void Tick(const float DeltaTime) = 0;
    virtual void Release() = 0;

    std::unique_ptr<IMessageHandler> MessageHandler;
};
