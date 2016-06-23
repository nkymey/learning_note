# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
# project (app_test)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
#set(APP_SRC main.c)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/debug/bin)

# 设置工程需要的头文件路径（包括工程内的）
include_directories(../include)

# 指定生成目标
add_executable(app_test ${DIR_SRCS})

# 添加链接库
target_link_libraries(app_test libhelloworld)

