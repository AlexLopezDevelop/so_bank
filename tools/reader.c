//
// Created by Alex Lopez on 19/9/21.
//
#include <stdio.h>
#include "reader.h"

#define MAX_SURNAME 2
#define END_FILE '\n'

int leerCuentas(char *fileName, Banco *banco) {

    int fd;
    fd = open(fileName, O_RDONLY);

    if (errorAbrir(fd, fileName) == 1) {
        return 1;
    }

    banco->cuentas = (Cuenta *) malloc(sizeof(Cuenta));
    banco->totalCuentas = 0;

    char *lineaFile = NULL;
    int endFile = 0;
    int i = 0;

    while (!endFile) {

        banco->totalCuentas = banco->totalCuentas + 1;

        lineaFile = (char *) readLineFile(fd, END_FILE);
        strcpy(banco->cuentas[i].numero, lineaFile);
        strcpy(banco->cuentas[i].iban.numeroDeCuenta, lineaFile);

        lineaFile = (char *) readLineFile(fd, END_FILE);
        strcpy(banco->cuentas[i].caducidad, lineaFile);

        lineaFile = (char *) readLineFile(fd, END_FILE);
        strcpy(banco->cuentas[i].codigoSeguridad, lineaFile);

        lineaFile = (char *) readLineFile(fd, END_FILE);
        strcpy(banco->cuentas[i].swift.identificadorPais, lineaFile);
        strcpy(banco->cuentas[i].iban.identificadorPais, lineaFile);

        lineaFile = (char *) readLineFile(fd, END_FILE);
        strcpy(banco->cuentas[i].iban.digitosControl, lineaFile);

        lineaFile = (char *) readLineFile(fd, END_FILE);
        strcpy(banco->cuentas[i].swift.codigoIdentidad, lineaFile);

        lineaFile = (char *) readLineFile(fd, END_FILE);
        strcpy(banco->cuentas[i].swift.codigoLocalidad, lineaFile);

        lineaFile = (char *) readLineFile(fd, END_FILE);
        strcpy(banco->cuentas[i].swift.codigoOficina, lineaFile);

        lineaFile = (char *) readLineFile(fd, END_FILE);
        strcpy(banco->cuentas[i].idClientes, lineaFile);

        liberarMemoria(lineaFile);
        endFile = checkEOF(fd);

        if (!endFile) {
            banco->cuentas = (Cuenta *) realloc(banco->cuentas, sizeof(Cuenta) * (banco->totalCuentas));
            i++;
        }
    }

    close(fd);
    return 0;
}

int leerClientes(char *fileName, Banco *banco) {

    int fd;
    fd = open(fileName, O_RDONLY);

    if (errorAbrir(fd, fileName) == 1) {
        return 1;
    }

    int endFile = 0;
    int i = 0;

    banco->clientes = malloc(sizeof(Cliente));
    banco->totalClientes = banco->totalClientes + 1;

    while (!endFile) {
        char *lineaFile = NULL;
        char nombre[30];

        // Identificador
        lineaFile = (char *) readLineFile(fd, ' ');
        banco->clientes[i].identificador = malloc(strlen(lineaFile));
        banco->clientes[i].identificador = lineaFile;
        readLineFileByCharacter(fd, 2);

        // Nombre + Surname
        lineaFile = (char *) readLineFile(fd, ' ');
        strcpy(nombre, lineaFile);
        strcat(nombre, " ");

        for (int j = 1; j <= MAX_SURNAME; ++j) {
            lineaFile = (char *) readLineFile(fd, ' ');
            strcat(nombre, lineaFile);
            if (j != MAX_SURNAME) {
                strcat(nombre, " ");
            }
        }

        strcpy(banco->clientes[i].nombre, nombre);
        readLineFileByCharacter(fd, 2);

        //telefono
        lineaFile = (char *) readLineFile(fd, '\n');
        strcpy(banco->clientes[i].telefono, lineaFile);

        liberarMemoria(lineaFile);
        endFile = checkEOF(fd);

        if (!endFile) {
            banco->totalClientes = banco->totalClientes + 1;
            banco->clientes = (Cliente *) realloc(banco->clientes, sizeof(Cuenta) * (banco->totalClientes));
            i++;
        }
    }

    close(fd);

    return 0;
}
