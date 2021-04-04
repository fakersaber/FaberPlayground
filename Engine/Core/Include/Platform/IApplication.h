#pragma once

#include "PlatformCommon.h"

#if 1
    #define DEFINE_APPLICATION_MAIN(appClass)                     \
    extern int WindowsMain(int argc, char** argv);                \
    int main(int argc, char** argv)                               \
	{                                                             \
        return WindowsMain(argc, argv);                           \
	}
#endif

void testfunc();