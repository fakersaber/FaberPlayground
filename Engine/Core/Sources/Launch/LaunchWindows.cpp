#include "Launch/Launch.h"

#include <windows.h>
#include <vector>
#include <string>

std::vector<std::string> g_CmdLine;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	int argc = 0;
	LPWSTR* argv = ::CommandLineToArgvW(::GetCommandLineW(), &argc);
	for (int32 i = 0; i < argc; ++i)
	{
		char* buf = new char[2048];
		wcstombs(buf, argv[i], 2048);
		g_CmdLine.push_back(buf);
	}

	return EngineLuncher::GuardedMain(g_CmdLine);
}