set(APPNAME hello)
set(APPSRC main.cpp)
add_executable(${APPNAME} ${APPSRC})
target_link_libraries(${APPNAME} Hello)