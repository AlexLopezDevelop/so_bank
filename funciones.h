//
// Created by Alex Lopez on 17/9/21.
//

#ifndef LSTARTER_FUNCIONES_H
#define LSTARTER_FUNCIONES_H

// Librerias GENERALES
#include <stdio.h>      // sprintf
#include <unistd.h>     // hauria de ser red write open y close
#include <sys/types.h>  //
#include <fcntl.h>      // Modos de opertura : open(), O_RDONLY
#include <string.h>     // strlen, strcmp
#include <stdlib.h>     // malloc, realloc
#include <time.h>       // fecha del sistema


// FICHEROS
#define FILE1 "Clientes.txt"
#define FILE2 "Cuentas.txt"

void liberarMemoria(void *ptr);

int errorArgumentos(int argc, char *argv[], int num_argumentos);

int errorAbrir(int fd, char *nombre_f);

void readInput(char **string);

void display(char *string);

void displayLn(char *string);

char *readLineFileByCharacter(int fd, int charactersToRead);

char * readLineFile(int fd, char hasta);

int checkEOF(int fd);

int esNumero(char car);

char *invertirCadena(char cadena[]);

void showDate();

#endif //LSTARTER_FUNCIONES_H
