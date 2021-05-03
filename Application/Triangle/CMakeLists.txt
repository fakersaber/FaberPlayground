file(GLOB TRIANGLE_SRC "*.cpp" "*.hpp" "*.h")

#决定使用哪个平台的Luncher
if(WIN32)
    SET(MainLaunch
        ${CMAKE_SOURCE_DIR}/Engine/Core/Sources/Launch/LaunchWindows.cpp
    )
endif(WIN32)

message(${TRIANGLE_SRC})

set(AppName "TriangleApp")

add_executable(
    ${AppName} 
    ${MainLaunch}
    ${TRIANGLE_SRC}
    #${CMAKE_CURRENT_SOURCE_DIR}/Triangle.h
    #${CMAKE_CURRENT_SOURCE_DIR}/Triangle.cpp
)

if(WIN32)
    target_link_libraries(
        ${AppName} 
        ${ALL_LIBS} 
        ${WINLIBS}
    )
endif(WIN32)


