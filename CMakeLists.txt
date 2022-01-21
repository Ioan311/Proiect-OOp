cmake_minimum_required(VERSION 3.20)
project(Proiect_OOp)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proiect_OOp
        main.cpp Cpp/utilizator.cpp Headers/utilizator.h Cpp/reactie.cpp Headers/reactie.h Cpp/mesaj.cpp Headers/mesaj.h Cpp/chat.cpp Headers/chat.h Cpp/grup.cpp Headers/grup.h Cpp/postare.cpp Headers/postare.h Cpp/data_invalida.cpp Headers/data_invalida.h Cpp/Story.cpp Headers/Story.h Cpp/Profile.cpp Headers/Profile.h)
