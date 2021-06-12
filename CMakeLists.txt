cmake_minimum_required(VERSION 3.15.0 FATAL_ERROR)

set(NAME FaberPlayground)

project(${NAME} VERSION 0.1.0)

#开启文件夹层级生成
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(WIN32)
	message(STATUS $ENV{VULKAN_SDK}/lib)
	find_library(Vulkan_LIBRARY NAMES vulkan-1 PATHS "$ENV{VULKAN_SDK}/lib"  REQUIRED)
	IF (Vulkan_LIBRARY)
		set(Vulkan_FOUND ON)
	ENDIF()

	IF (Vulkan_FOUND)
		message(STATUS "Vulkan Found")
	ENDIF()
endif(WIN32)

# Compiler specific stuff
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#https://github.com/google/berrydb/blob/master/CMakeLists.txt
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  	# Disable C++ exceptions.
  	string(REGEX REPLACE "/EH[a-z]+" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHs-c-")

	# Set Warning
	if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    	string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
    	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  	endif()

	#设置入口为main, 且为普通窗口,不为Console
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS") 
	#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup") 
  	add_definitions(-D_HAS_EXCEPTIONS=0) #-D后面跟宏
	add_definitions(-DPLATFORM_WINDOWS)
endif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")

# if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
#   # Update if necessary
#   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
# endif()

#TODO: 修改输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

set(ALL_LIBS
	${Vulkan_LIBRARY}
	Core
)

#添加全局路径
include_directories(Engine/Core/Include)

#添加Lib和EXE
add_subdirectory(Engine/Core)
add_subdirectory(Application/Triangle)