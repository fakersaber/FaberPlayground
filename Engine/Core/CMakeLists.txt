# set(Faber_Math_HEAD "Include/Math/*.h" "Include/Math/*.hpp")
# set(Faber_Math_SRC "Include/Math/*.cpp")

file(GLOB Faber_PLATFORM_HEAD "Include/Platform/*.h" "Include/Platform/*.hpp")

#注意Cmake的set variable需要创建,不能随便调用set
IF(WIN32)
    file(GLOB Faber_PLATFORM_SRC "Sources/Platform/Windows/*.cpp")
ENDIF(WIN32)

set(LibName "Core")

# message(STATUS ${Faber_PLATFORM_SRC})

add_library(${LibName} STATIC 
    # ${Faber_Math_HEAD}
    # ${Faber_Math_SRC}

    ${Faber_PLATFORM_HEAD}
    "Sources/Platform/Windows/WindowsBase.cpp"
)

set_target_properties(${LibName} PROPERTIES LINKER_LANGUAGE CXX)

source_group(Core\\Include\\Platform FILES ${Faber_PLATFORM_HEAD})
source_group(Core\\Sources\\Platform\\Windows FILES ${Faber_PLATFORM_SRC})


