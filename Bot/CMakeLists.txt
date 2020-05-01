cmake_minimum_required(VERSION 3.15)
project(Bot C)

set(CMAKE_C_STANDARD 99)

add_executable(bot main.c ../Projeto/Interface.c "../Projeto/Camada de Dados.c" ../Projeto/Logica.c ../Projeto/ListasLigadas.c)