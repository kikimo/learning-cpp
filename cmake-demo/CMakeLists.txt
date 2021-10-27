cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

option(USE_MYMATH "User tutorial provided math implemlentation" ON)
configure_file(TutorialConfig.h.in TutorialConfig.h)

if (USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
endif()


# add_library(MathFunctions mysqrt.cpp)
add_executable(Tutorial tutorial.cpp)

# what's PUBLIC
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})
target_include_directories(Tutorial PUBLIC
                            "${PROJECT_BINARY_DIR}")
