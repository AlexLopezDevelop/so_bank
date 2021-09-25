//
// Created by Alex Lopez on 20/9/21.
//

#ifndef LSTARTER_CLIENTE_H
#define LSTARTER_CLIENTE_H

#include "cuenta.h"

typedef struct {
    Cuenta * cuenta;
    int totalCuentas;
} CuentasCliente;

typedef struct {
    char * identificador;
    char nombre[30];
    char telefono[12];
    CuentasCliente * cuentasCliente;
} Cliente;

#endif //LSTARTER_CLIENTE_H
