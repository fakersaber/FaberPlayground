#include "Platform/Windows/WinApplication.h"

#include <cassert>
#include <windows.h>

HINSTANCE WinApplication::AppHInstance = nullptr;

WindowsMessageHandler::WindowsMessageHandler()
	: IMessageHandler()
{

}

WindowsMessageHandler::~WindowsMessageHandler(){

}

void WindowsMessageHandler::OnWindowClose(){

}

std::unique_ptr<IPlatformAppication> IPlatformAppication::CreatePlatformApp() {
	return std::make_unique<WinApplication>();
}

WinApplication::WinApplication()
	: IPlatformAppication()
{
	MessageHandler = std::make_unique<WindowsMessageHandler>();
}

WinApplication::~WinApplication(){
	MessageHandler.reset();
}

void WinApplication::Init(int32 width, int32 height, const char* title){
	
}

void WinApplication::Tick(const float DeltaTime){

}

void WinApplication::Release(){
	
}


