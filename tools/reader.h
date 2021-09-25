//
// Created by Alex Lopez on 19/9/21.
//

#ifndef LSTARTER_READER_H
#define LSTARTER_READER_H

#include "../funciones.h"
#include "../models/cliente.h"
#include "../models/banco.h"
#include "../models/iban.h"

int leerCuentas(char *fileName, Banco *banco);

int leerClientes(char *fileName, Banco * banco);

#endif //LSTARTER_READER_H
