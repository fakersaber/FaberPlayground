# set(Faber_Math_HEAD "Include/Math/*.h" "Include/Math/*.hpp")
# set(Faber_Math_SRC "Include/Math/*.cpp")

file(GLOB Faber_PLATFORM_HEAD "Include/Platform/*.h" "Include/Platform/*.hpp")
file(GLOB Faber_PLATFORM_WINDOWS_SRC "Sources/Platform/Windows/*.cpp")

IF(WIN32)
    set(Faber_PLATFORM_SRC, ${Faber_PLATFORM_WINDOWS_SRC})
ENDIF(WIN32)

set(LibName "Core")

add_library(${LibName} STATIC 
    # ${Faber_Math_HEAD}
    # ${Faber_Math_SRC}

    ${Faber_PLATFORM_HEAD}
    ${Faber_PLATFORM_SRC}
)

set_target_properties(${LibName} PROPERTIES LINKER_LANGUAGE CXX)

# source_group(Core\\Include\\Math FILES ${Faber_Math_HEAD})
# source_group(Core\\Source\\Math FILES ${Faber_Math_SRC})

source_group(Core\\Include\\Platform FILES ${Faber_PLATFORM_HEAD})
source_group(Core\\Source\\Platform FILES ${Faber_PLATFORM_SRC})


