cmake_minimum_required(VERSION 3.31)
project(inheritance_example)

set(CMAKE_CXX_STANDARD 20)

add_executable(inheritance_example main.cpp
        bankAccount.cpp
        bankAccount.h
        checkingAccount.cpp
        checkingAccount.h)
