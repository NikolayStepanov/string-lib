add_executable(string_program main.cpp)

include_directories(../string_lib)

target_link_libraries(string_program string_lib)