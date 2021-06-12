# pragma once

typedef unsigned char		uint8;
typedef unsigned short int	uint16;
typedef unsigned int		uint32;
typedef unsigned long long	uint64;

typedef	signed char			int8;
typedef signed short int	int16;
typedef signed int			int32;
typedef signed long long	int64;

#if !defined(PLATFORM_WINDOWS)
	#define PLATFORM_WINDOWS 0
#endif

#if !defined(PLATFORM_ANDROID)
	#define PLATFORM_ANDROID 0
#endif
