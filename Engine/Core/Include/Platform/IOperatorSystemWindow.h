#pragma once

// #include <windows.h>
// #include <stdint.h>


// typedef struct WindowHandle
// {
// 	void*                    window;    //hWnd
// } WindowHandle;

// typedef struct RectDesc
// {
// 	int32_t left;
// 	int32_t top;
// 	int32_t right;
// 	int32_t bottom;
// } RectDesc;

// inline int getRectWidth(const RectDesc& rect) { return rect.right - rect.left; }

// inline int getRectHeight(const RectDesc& rect) { return rect.bottom - rect.top; }

// typedef struct
// {
// 	WindowHandle handle;
// 	RectDesc windowedRect;
// 	RectDesc fullscreenRect;
// 	RectDesc clientRect;
// 	uint32_t windowsFlags;
// 	bool fullScreen;
// 	bool cursorTracked;
// 	bool iconified;
// 	bool maximized;
// 	bool minimized;
// 	bool hide;
// 	bool noresizeFrame;
// 	bool borderlessWindow;
// 	bool overrideDefaultPosition;
// 	bool centered;
// 	bool forceLowDPI;
// } WindowsDesc;

// typedef struct Resolution
// {
// 	uint32_t mWidth;
// 	uint32_t mHeight;
// } Resolution;

// // Monitor data
// //
// typedef struct
// {
// 	RectDesc          monitorRect;
// 	RectDesc          workRect;
//     uint2             dpi;
//     uint2             physicalSize;
// 	// This size matches the static size of DISPLAY_DEVICE.DeviceName

// 	TCHAR             adapterName[32];
// 	TCHAR             displayName[32];
// 	TCHAR             publicAdapterName[128];
// 	TCHAR             publicDisplayName[128];
//     // char              adapterName[32];
// 	// char              displayName[32];
// 	// char              publicAdapterName[64];
// 	// char              publicDisplayName[64];

// 	Resolution*       resolutions;
// 	Resolution        defaultResolution;
// 	uint32_t          resolutionCount;
// 	bool              modesPruned;
// 	bool              modeChanged;
// } MonitorDesc;

// // API functions
// void requestShutdown();

// // Custom processing of OS pipe messages
// typedef int32_t(*CustomMessageProcessor)(WindowsDesc* pWindow, void* msg);
// void setCustomMessageProcessor(CustomMessageProcessor proc);

// // Window handling
// void openWindow(const char* app_name, WindowsDesc* winDesc);
// void closeWindow(const WindowsDesc* winDesc);
// void setWindowRect(WindowsDesc* winDesc, const RectDesc& rect);
// void setWindowSize(WindowsDesc* winDesc, unsigned width, unsigned height);
// void toggleBorderless(WindowsDesc* winDesc, unsigned width, unsigned height);
// void toggleFullscreen(WindowsDesc* winDesc);
// void showWindow(WindowsDesc* winDesc);
// void hideWindow(WindowsDesc* winDesc);
// void maximizeWindow(WindowsDesc* winDesc);
// void minimizeWindow(WindowsDesc* winDesc);
// void centerWindow(WindowsDesc* winDesc);

// // Mouse and cursor handling
// void* createCursor(const char* path);
// void setCursor(void* cursor);
// void showCursor();
// void hideCursor();
// bool isCursorInsideTrackingArea();
// void setMousePositionRelative(const WindowsDesc* winDesc, int32_t x, int32_t y);
// void setMousePositionAbsolute(int32_t x, int32_t y);

// void getRecommendedResolution(RectDesc* rect);
// // Sets video mode for specified display
// void setResolution(const MonitorDesc* pMonitor, const Resolution* pRes);

// MonitorDesc* getMonitor(uint32_t index);
// uint32_t     getMonitorCount();
// float2       getDpiScale();

// bool getResolutionSupport(const MonitorDesc* pMonitor, const Resolution* pRes);

// // Shell commands

// /// @param stdOutFile The file to which the output of the command should be written. May be NULL.
// int systemRun(const char *command, const char **arguments, size_t argumentCount, const char* stdOutFile);
