set (LIVE_SRCS_BASE "${CMAKE_SOURCE_DIR}/src")

include_directories(${LIVE_SRCS_BASE})
include_directories(${LIVE_SRCS_BASE}/Engine)


set (LIVE_SRCS_MAIN 
	"${LIVE_SRCS_BASE}/main.cpp"
)


set (LIVE_SRCS_GAME 
	"${LIVE_SRCS_BASE}/Engine/game.cpp"
	"${LIVE_SRCS_BASE}/Engine/options.cpp"
)

add_executable(live 
	${LIVE_SRCS_MAIN}
	${LIVE_SRCS_GAME}
)