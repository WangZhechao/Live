# CMakeList.txt: live 的 CMake 项目，包括源和定义
# 此处特定于项目的逻辑。
#
cmake_minimum_required (VERSION 2.8)

# 工程名称
project(LIVE)


# 配置文件
configure_file(
	"${PROJECT_SOURCE_DIR}/src/config.h.in"
	"${PROJECT_SOURCE_DIR}/src/config.h"
)


# 编译平台
option (RUN_WIN32_PLATFORM "run win32 platform" on)


if (RUN_WIN32_PLATFORM)
	message(status "current platform: Windows")
	include("${PROJECT_SOURCE_DIR}/cmake/run_win32.cmake")
else()
	message(status "current platform: psv")
	include("${PROJECT_SOURCE_DIR}/cmake/run_psv.cmake")
endif()


# TODO: 如有需要，请添加测试并安装目标。
