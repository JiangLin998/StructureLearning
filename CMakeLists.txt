cmake_minimum_required(VERSION 3.27)
project(Structure)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/List
                    ${CMAKE_SOURCE_DIR}/Queue
                    ${CMAKE_SOURCE_DIR}/Stack
                    ${CMAKE_SOURCE_DIR}/Tree/
                    ${CMAKE_SOURCE_DIR}/Tree/BinarySearchTree
                    ${CMAKE_SOURCE_DIR}/Tree/BinaryTree
                    ${CMAKE_SOURCE_DIR}/Tree/BinarySearchStringTree)

add_executable(Structure main.cpp
        Queue/queue_array.cpp
        Queue/queue_list.cpp
        List/list.cpp
        Stack/stack_array.cpp
        Stack/stack_list.cpp
        Stack/stack_test.cpp
        Stack/stack_calculate.cpp
        Tree/tree_test.cpp
        Tree/BinarySearchTree/binary_search_tree.cpp
        Tree/BinaryTree/binary_tree.cpp
        Tree/BinarySearchStringTree/binary_search_string_tree.cpp)
