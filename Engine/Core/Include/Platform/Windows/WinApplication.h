#pragma once

#include <windows.h>
#include <unordered_set>
#include "Platform/IPlatformApplication.h"

class WinWindow;

class WinApplication : public IPlatformAppication {
public:
	static void SetWinApplicationForWindow(WinApplication* InWinApplicationInstance);
	static void SetWinApplicationForHINSTANCE(HINSTANCE InWinApplicationHINSTANCE);
	static WinApplication* GetWinApplicationInstance();
	static HINSTANCE GetWinApplicationHINSTANCE();
public:
	WinApplication();
	virtual ~WinApplication();
	virtual void Init(int32 width, int32 height, const char* title) override;
	virtual bool Tick(const float DeltaTime) override;
	virtual void Release() override;
	void OnWindowClose();
private:
	bool bIsApplicationExit;
	std::unique_ptr<WinWindow> ApplicationWindowPtr; //目前全部实现写在各自类中
	std::unordered_set<HWND> ApplicationWindows;

	//[Global Resources]
	static HINSTANCE AppHInstance;
	static WinApplication* WinApplicationInstance;
};