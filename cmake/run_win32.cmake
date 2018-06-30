include("${PROJECT_SOURCE_DIR}/cmake/common_src.cmake")

add_executable(alive WIN32 
	${LIVE_SRCS_MAIN}
	${LIVE_SRC_BASE}
	${LIVE_SRCS_ENGINE}
)