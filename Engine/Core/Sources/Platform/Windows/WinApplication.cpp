#include "Platform/Windows/WinApplication.h"
#include "Platform/Windows/WinWindow.h"
#include <cassert>
#include <windows.h>

HINSTANCE WinApplication::AppHInstance = nullptr;
WinApplication* WinApplication::WinApplicationInstance = nullptr;

std::unique_ptr<IPlatformAppication> IPlatformAppication::CreatePlatformApp() {
	return std::make_unique<WinApplication>();
}

void WinApplication::SetWinApplicationForWindow(WinApplication* InWinApplicationInstance) {
	WinApplication::WinApplicationInstance = InWinApplicationInstance;
}

void WinApplication::SetWinApplicationForHINSTANCE(HINSTANCE InWinApplicationHINSTANCE) {
	WinApplication::AppHInstance = InWinApplicationHINSTANCE;
}

WinApplication* WinApplication::GetWinApplicationInstance() {
	return WinApplication::WinApplicationInstance;
}

HINSTANCE WinApplication::GetWinApplicationHINSTANCE() {
	return WinApplication::AppHInstance;
}

WinApplication::WinApplication()
	: IPlatformAppication()
	, bIsApplicationExit(false)
{
	ApplicationWindowPtr = std::make_unique<WinWindow>();
}

WinApplication::~WinApplication(){
	ApplicationWindowPtr.reset();
}

void WinApplication::Init(int32 Width, int32 Height, const char* Title){
	SetWinApplicationForWindow(this);
	ApplicationWindowPtr->Init(Width, Height, Title);
}

bool WinApplication::Tick(const float DeltaTime){
	ApplicationWindowPtr->Tick(DeltaTime);
	return bIsApplicationExit;
}

void WinApplication::Release(){
	ApplicationWindowPtr->Release();
}

void WinApplication::OnWindowClose(){
	bIsApplicationExit = true;
}