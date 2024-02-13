cmake_minimum_required(VERSION 3.5)

project(IntegerArray LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(IntegerArray
    main.cpp
    integerarray.h
    integerarray.cpp
    arrayexceptions.h)

install(TARGETS IntegerArray
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
