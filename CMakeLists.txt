cmake_minimum_required(VERSION 3.30)
project(lab2_marti)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab2_marti main.cpp
        colectie/Colectie.cpp
        colectie/Colectie.h
        tranzactie/Tranzactie.cpp
        tranzactie/Tranzactie.h
        atm/ATM.cpp
        atm/ATM.h)
