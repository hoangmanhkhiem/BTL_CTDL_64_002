cmake_minimum_required(VERSION 3.28)
project(PhanA)

set(CMAKE_CXX_STANDARD 17)

add_executable(PhanA main.cpp
        PhuongTien.hpp
        ThoiGian.hpp
        DanhsachPhuongTien.hpp)
