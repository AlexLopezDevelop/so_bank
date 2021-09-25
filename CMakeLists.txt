cmake_minimum_required(VERSION 3.20)
project(LStarter C)

set(CMAKE_C_STANDARD 99)

add_executable(LStarter main.c funciones.c funciones.h tools/reader.c tools/reader.h models/cliente.h models/cuenta.h models/iban.h models/swift.h models/banco.h tools/interfaz.c tools/interfaz.h tools/servicioBanco.c tools/servicioBanco.h)
