# CMakeList.txt: live 的 CMake 项目，包括源和定义
# 此处特定于项目的逻辑。
#
cmake_minimum_required (VERSION 2.8)

# 编译平台
option (RUN_WIN32_PLATFORM "run win32 platform" on)

if (RUN_WIN32_PLATFORM)
	message(status "current platform: Windows")
else()
	message(status "current platform: PSV")
	if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
		if(DEFINED ENV{VITASDK})
			set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
		else()
			message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
		endif()
	endif()
endif()


# 工程名称
project(ALIVE)


# 配置文件
configure_file(
	"${PROJECT_SOURCE_DIR}/src/config.h.in"
	"${PROJECT_SOURCE_DIR}/src/config.h"
)


# 第三方库
set (LIVE_SRCS_3RDPARTY "${CMAKE_SOURCE_DIR}/3rdParty")
include_directories(${LIVE_SRCS_3RDPARTY})


#TODO: delete it!
if (RUN_WIN32_PLATFORM)
link_directories("F:\\psv\\live\\alive\\build")
link_libraries("SDL2.lib SDL2main")
endif()


#cmake
if (RUN_WIN32_PLATFORM)
	message(status "current platform: Windows")
	include("${PROJECT_SOURCE_DIR}/cmake/run_win32.cmake")
else()
	message(status "current platform: psv")
	include("${PROJECT_SOURCE_DIR}/cmake/run_psv.cmake")
endif()

# TODO: 如有需要，请添加测试并安装目标。