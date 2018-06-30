if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()


include ("${VITASDK}/share/vita.cmake" REQUIRED)

set(SHORT_NAME alive)
set (VITA_APP_NAME "${SHORT_NAME}")
set (VITA_TITLEID "VSDK66666")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")


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


add_executable("${SHORT_NAME}" 
	${LIVE_SRCS_MAIN}
	${LIVE_SRC_BASE}
	${LIVE_SRCS_ENGINE}
)


target_link_libraries("${SHORT_NAME}"
  SDL2
  vita2d
  SceDisplay_stub
  SceCtrl_stub
  SceAudio_stub
  SceSysmodule_stub
  SceGxm_stub
  SceCommonDialog_stub
  SceTouch_stub
  SceHid_stub
  m
)


vita_create_self(${SHORT_NAME}.self ${SHORT_NAME})
vita_create_vpk(${SHORT_NAME}.vpk ${VITA_TITLEID} ${SHORT_NAME}.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE res/sce_sys/icon0.png sce_sys/icon0.png
  FILE res/sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
  FILE res/sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
  FILE res/sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
)