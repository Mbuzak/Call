add_library(call STATIC linked_list.c quicksort.c)
target_include_directories(call PRIVATE ${CMAKE_SOURCE_DIR}/include)
