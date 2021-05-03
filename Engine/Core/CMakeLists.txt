file(GLOB Faber_ENGINE_HEAD "Include/*.h" "Include/*.hpp")
file(GLOB Faber_ENGINE_SRC "Sources/*.cpp" "Sources/*.h" "Sources/*.hpp")

file(GLOB Faber_LAUNCH_HEAD "Include/Launch/*.h" "Include/Launch/*.hpp")
file(GLOB Faber_LAUNCH_SRC "Sources/Launch/Launch.cpp")

file(GLOB Faber_APPLICATIONBASE_HEAD "Include/Application/*.h")

file(GLOB Faber_PLATFORM_COMMON_HEAD "Include/Platform/*.h" "Include/Platform/*.hpp")
IF(WIN32)
    file(GLOB Faber_PLATFORM_HEAD "Include/Platform/Windows/*.h")
    file(GLOB Faber_PLATFORM_SRC "Sources/Platform/Windows/*.cpp" "Sources/Platform/Windows/*.h" "Sources/Platform/Windows/*.hpp")
ENDIF(WIN32)

set(LibName "Core")

add_library(${LibName} STATIC 

    #engine
    ${Faber_ENGINE_HEAD}
    ${Faber_ENGINE_SRC}

    #Application
    ${Faber_APPLICATIONBASE_HEAD}

    #launcher
    ${Faber_LAUNCH_HEAD}
    ${Faber_LAUNCH_SRC}

    #Platform
    ${Faber_PLATFORM_COMMON_HEAD}
    ${Faber_PLATFORM_HEAD}
    ${Faber_PLATFORM_SRC}
)

set_target_properties(${LibName} PROPERTIES LINKER_LANGUAGE CXX)

source_group(Core\\Include\\ FILES ${Faber_ENGINE_HEAD})
source_group(Core\\Sources\\ FILES ${Faber_ENGINE_SRC})

source_group(Core\\Include\\Application\\ FILES ${Faber_APPLICATIONBASE_HEAD})

source_group(Core\\Include\\Luncher\\ FILES ${Faber_LAUNCH_HEAD})
source_group(Core\\Sources\\Luncher\\ FILES ${Faber_LAUNCH_SRC})

source_group(Core\\Include\\Platform\\ FILES ${Faber_PLATFORM_COMMON_HEAD})
IF(WIN32)
    source_group(Core\\Include\\Platform\\Windows\\ FILES ${Faber_PLATFORM_HEAD})
ENDIF(WIN32)
source_group(Core\\Sources\\Platform\\ FILES ${Faber_PLATFORM_SRC})


