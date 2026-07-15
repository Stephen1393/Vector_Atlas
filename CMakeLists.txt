cmake_minimum_required(VERSION 3.20)

project(VectorAtlas)

find_package(Crow REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    VectorAtlas
    server/server.cpp
    extraction/text.cpp
    helpers/opendoc.cpp

)

##test executable

add_executable(
    scratch_test
    scratch_test/scratch.cpp
    extraction/text.cpp
    helpers/opendoc.cpp
    )


target_link_libraries(
    VectorAtlas
    PRIVATE
    Crow::Crow
    mupdf
)

target_link_libraries(
    scratch_test
    PRIVATE
    mupdf
)