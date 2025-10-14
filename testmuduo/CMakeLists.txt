cmake_minimum_required(VERSION 3.0)

project(main)

# 配置编译选项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

# 配置头文件搜索路径
# include_directories()
# 配置库文件搜索路径
# link_directories()

# 添加依赖的文件
set(SRC_LIST ./test_muduo.cpp)

# 将当前文件夹下的文件都加入
# aux_source_directory(. SRC_LIST)


# 生成可执行文件
add_executable(server ${SRC_LIST})

# 链接目标
target_link_libraries(server muduo_net muduo_base pthread)
