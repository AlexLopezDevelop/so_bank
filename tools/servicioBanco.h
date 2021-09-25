//
// Created by Alex Lopez on 24/9/21.
//

#ifndef LSTARTER_SERVICIOBANCO_H
#define LSTARTER_SERVICIOBANCO_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "../models/banco.h"

#define BACKUP_FILE_NAME "Info.txt"

CuentasCliente obtenerCuentaPorIdCliente(Banco * banco,int idCliente);

Cuenta obtenerCuentaPorId(Banco * banco, int numeroCuenta);

Cliente obtenerClientePorId(Banco * banco,int idCliente);

int realizarBackup(Banco * banco);

#endif //LSTARTER_SERVICIOBANCO_H
