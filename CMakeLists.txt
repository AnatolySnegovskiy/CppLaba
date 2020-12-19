cmake_minimum_required(VERSION 3.17)
project(StringLaba)

set(CMAKE_CXX_STANDARD 14)

add_executable(StringLaba main.cpp
        Strings/Action.cpp Strings/Action.h
        Strings/AString.h
        Strings/Factory.cpp Strings/Factory.h
        Strings/HexString.cpp Strings/HexString.h
        Strings/Menu.cpp Strings/Menu.h
        Strings/ShowBin.cpp Strings/ShowBin.h
        Strings/ShowDec.cpp Strings/ShowDec.h
        Strings/ShowStr.cpp Strings/ShowStr.h
        Strings/SymbString.h
        Strings/BinString.cpp Strings/BinString.h Strings/OctString.cpp Strings/OctString.h Strings/ShowOct.cpp Strings/ShowOct.h Strings/ShowHex.cpp Strings/ShowHex.h Strings/DecString.cpp Strings/DecString.h Strings/AString.cpp)