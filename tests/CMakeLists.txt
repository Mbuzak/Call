add_executable(test_linked_list test_linked_list.c)
target_include_directories(test_linked_list PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(test_linked_list PRIVATE call)
add_test(NAME test_linked_list COMMAND test_linked_list)
