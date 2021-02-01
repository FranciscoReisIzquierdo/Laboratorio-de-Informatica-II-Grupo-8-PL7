cmake_minimum_required(VERSION 3.15)
project(ProjetoLI2 C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjetoLI2 main.c "Logica.c" "Logica.h" Interface.c Interface.h "Camada de Dados.c" "Camada de Dados.h" ListasLigadas.c ListasLigadas.h) 
