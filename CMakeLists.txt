cmake_minimum_required(VERSION 3.20)
project(Kautil
        LANGUAGES C CXX
        VERSION 0.0.0.0
        )
set(CMAKE_CXX_STANDARD 11)

unset(srcs)
set(__t kautil_algorithm_compare_similarity)
add_library(${__t} STATIC)
file(GLOB srcs ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)
target_sources(${__t} PRIVATE ${srcs})
add_library(kautil::algorithm::compare_similarity ALIAS ${__t})
unset(srcs)

set(__t tmain_compare_similarity)
add_executable(${__t})
target_sources(${__t} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/unit_test.cc)
target_link_libraries(${__t} PRIVATE kautil::algorithm::compare_similarity)
target_compile_definitions(${__t} PRIVATE TMAIN_COMPAIR_SIMILARITY)

