//
// Created by Alex Lopez on 20/9/21.
//

#include "swift.h"
#include "iban.h"

#ifndef LSTARTER_CUENTA_H
#define LSTARTER_CUENTA_H

typedef struct {
    char numero[17];
    char caducidad[5];
    char codigoSeguridad[4];
    Iban iban;
    Swift swift;
    char idClientes[100];
} Cuenta;

#endif //LSTARTER_CUENTA_H
