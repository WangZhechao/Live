set (LIVE_SRCS_BASE "${CMAKE_SOURCE_DIR}/src")

include_directories(${LIVE_SRCS_BASE})

set (LIVE_SRCS_MAIN ${LIVE_SRCS_BASE}/main.cpp)

add_executable(live ${LIVE_SRCS_MAIN})