cmake_minimum_required(VERSION 3.22)

project(Calculator)

aux_source_directory(./src DIR_SRCS)

include_directories(include)

add_executable(Calculator ${DIR_SRCS})

