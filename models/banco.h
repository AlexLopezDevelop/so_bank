//
// Created by Alex Lopez on 20/9/21.
//

#ifndef LSTARTER_BANCO_H
#define LSTARTER_BANCO_H

#include "cuenta.h"
#include "cliente.h"

typedef struct {
    Cuenta * cuentas;
    Cliente * clientes;
    int totalCuentas;
    int totalClientes;
}Banco;

#endif //LSTARTER_BANCO_H