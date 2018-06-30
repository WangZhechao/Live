set (LIVE_SRCS_DIR			"${CMAKE_SOURCE_DIR}/src")
set (LIVE_SRCS_DIR_BASE		"${LIVE_SRCS_DIR}/Base")
set (LIVE_SRCS_DIR_ENGINE	"${LIVE_SRCS_DIR}/Engine")


include_directories(${LIVE_SRCS_DIR})
include_directories(${LIVE_SRCS_DIR_BASE})
include_directories(${LIVE_SRCS_DIR_ENGINE})


set (LIVE_SRCS_MAIN 
	"${LIVE_SRCS_DIR}/main.cpp"
)


set (LIVE_SRC_BASE
	"${LIVE_SRCS_DIR_BASE}/size.cpp"
)


set (LIVE_SRCS_ENGINE
	"${LIVE_SRCS_DIR_ENGINE}/game.cpp"
	"${LIVE_SRCS_DIR_ENGINE}/options.cpp"
	"${LIVE_SRCS_DIR_ENGINE}/renderer.cpp"
	"${LIVE_SRCS_DIR_ENGINE}/crossplatform.cpp"
)


add_executable(alive WIN32 
	${LIVE_SRCS_MAIN}
	${LIVE_SRC_BASE}
	${LIVE_SRCS_ENGINE}
)