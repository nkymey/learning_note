# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
# project (app_test)

# 设置工程需要的头文件路径（包括工程内的）
include_directories(../include)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

# 指定生成目标
add_library(libhelloworld STATIC ${DIR_LIB_SRCS})

set_target_properties(libhelloworld PROPERTIES OUTPUT_NAME "helloworld")
install(TARGETS libhelloworld
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib)
install(FILES ${PROJECT_SOURCE_DIR}/include/0.0.0_helloworld.h DESTINATION include)

#set(APP_SRC main.c)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/debug/lib)

# 添加链接库
#target_link_libraries(app_test libhelloworld)

