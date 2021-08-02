cmake_minimum_required(VERSION 2.8.12)

project(lab)

string(REGEX MATCH "^(.*)[\\/]labs[\\/].*$" repo "${CMAKE_CURRENT_SOURCE_DIR}")
list(APPEND CMAKE_MODULE_PATH ${CMAKE_MATCH_1}/tools)
include(labs)
