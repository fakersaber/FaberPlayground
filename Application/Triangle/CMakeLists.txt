file(GLOB TRIANGLE_SRC "*.cpp" "*.hpp" "*.h")
# file(GLOB BASE_HEADERS "*.hpp" "*.h")

set(AppName "Triangle")

add_executable(${AppName} ${TRIANGLE_SRC})

if(WIN32)
    target_link_libraries(${AppName} 
        ${ALL_LIBS} 
        ${WINLIBS}
    )
endif(WIN32)


