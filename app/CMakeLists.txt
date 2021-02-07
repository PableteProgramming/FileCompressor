set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_executable(main ${SRC_DIR}/main.cpp)

target_include_directories(main PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(main PRIVATE huffmancompression)
