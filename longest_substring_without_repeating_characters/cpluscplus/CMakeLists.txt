CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(LEETCODE_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS)

SET(CMAKE_VERBOSE_MAKEFILE OFF)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(CMAKE_CXX_FLAGS "-g -pipe -W -Wall -fPIC")

INCLUDE_DIRECTORIES(
    "."
)

LINK_DIRECTORIES(
)

IF (class STREQUAL hl)
    ADD_DEFINITIONS(-DHL=1)
    SET(SRC_LIST main.cpp longest_substring_without_repeating_characters_hl.hpp)
ENDIF()
IF (class STREQUAL pj)
    ADD_DEFINITIONS(-DPJ=1)
    SET(SRC_LIST main.cpp longest_substring_without_repeating_characters_pj.hpp)
ENDIF()

ADD_EXECUTABLE(longest_substring_without_repeating_characters ${SRC_LIST})
