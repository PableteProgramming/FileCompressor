set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_library(huffmancompression ${SRC_DIR}/Huffman.cpp)

target_include_directories(huffmancompression PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_sources(
    huffmancompression PRIVATE
    ${SRC_DIR}/FrequenceMap.cpp
    ${SRC_DIR}/Node.cpp
    ${SRC_DIR}/MapSorter.cpp
    ${SRC_DIR}/Tree.cpp
    ${SRC_DIR}/WriteFile.cpp
)