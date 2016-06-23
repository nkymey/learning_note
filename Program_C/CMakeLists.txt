# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (app_test)

set (app_test_VERSION_MAJOR 1)
set (app_test_VERSION_MINOR 0)

# 添加 math 子目录
add_subdirectory(main)
add_subdirectory(0.0.0_hello_world)

# 设置工程需要的头文件路径（包括工程内的）
INCLUDE_DIRECTORIES(./include)

# 构建一个 CPack 安装包
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${app_test_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${app_test_VERSION_MINOR}")
include (CPack)
