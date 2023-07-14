add_executable(graph main.cpp)

target_include_directories(graph PUBLIC ${MY_INCLUDE_DIR})

add_library(my_lib ${MY_INCLUDE_DIR}/igraph.h
            ${MY_INCLUDE_DIR}/matrix_graph.h matrix_graph.cpp
            ${MY_INCLUDE_DIR}/list_graph.h list_graph.cpp
            )

target_include_directories(my_lib PUBLIC ${MY_INCLUDE_DIR})

target_link_libraries(graph PRIVATE my_lib)

