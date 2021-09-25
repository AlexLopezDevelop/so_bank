//
// Created by Alex Lopez on 24/9/21.
//

#include <stdlib.h>
#include "servicioBanco.h"
#include "../funciones.h"

CuentasCliente obtenerCuentaPorIdCliente(Banco *banco, int idCliente) {
    char *pch;
    char idClientes[100];

    CuentasCliente cuentasCliente;
    cuentasCliente.totalCuentas = 0;
    cuentasCliente.cuenta = malloc(sizeof(Cuenta));
    for (int i = 0; i < banco->totalCuentas; ++i) {
        strcpy(idClientes, banco->cuentas[i].idClientes);
        pch = strtok(idClientes, " ,\0");
        while (pch != NULL) {
            if (atoi(pch) == idCliente) {
                if (cuentasCliente.totalCuentas != 0) {
                    cuentasCliente.cuenta = realloc(cuentasCliente.cuenta,
                                                     sizeof(CuentasCliente) * (cuentasCliente.totalCuentas + 1));
                }
                cuentasCliente.cuenta[cuentasCliente.totalCuentas] = banco->cuentas[i];
                cuentasCliente.totalCuentas = cuentasCliente.totalCuentas + 1;
            }
            pch = strtok(NULL, " ");
        }
    }

    return cuentasCliente;
}

Cuenta obtenerCuentaPorId(Banco *banco, int numeroCuenta) {
    Cuenta cuenta;

    for (int i = 0; i < banco->totalCuentas; ++i) {
        if (atoi(banco->cuentas[i].numero) == numeroCuenta) {
            cuenta = banco->cuentas[i];
        }
    }

    return cuenta;
}

Cliente obtenerClientePorId(Banco *banco, int idCliente) {
    Cliente cliente;

    for (int i = 0; i < banco->totalClientes; ++i) {
        if (atoi(banco->clientes[i].identificador) == idCliente) {
            cliente = banco->clientes[i];
        }
    }

    return cliente;
}

int realizarBackup(Banco *banco) {

    int fd;

    fd = open(BACKUP_FILE_NAME, O_RDWR | O_APPEND | O_CREAT,
              0666); // abrimos el fichero con las constantes apropiadas y permisos

    if (errorAbrir(fd, BACKUP_FILE_NAME)) {
        return 1;
    }

    for (int i = 0; i < banco->totalClientes; ++i) {
        write(fd, banco->clientes[i].nombre, sizeof(char) * strlen(banco->clientes[i].nombre));
        write(fd, "\n", sizeof(char));
        write(fd, banco->clientes[i].telefono, sizeof(char) * strlen(banco->clientes[i].telefono));
        write(fd, "\n", sizeof(char));

        int identificador = atoi(banco->clientes[i].identificador);
        CuentasCliente cuentasCliente = obtenerCuentaPorIdCliente(banco, identificador);
        Cuenta cuenta;
        char numeroCuentas[100];
        sprintf(numeroCuentas, "%d", cuentasCliente.totalCuentas);
        write(fd, numeroCuentas, sizeof(char));
        write(fd, "\n", sizeof(char));

        char numCuenta[100];
        char swiftCompleto[100];

        for (int j = 0; j < cuentasCliente.totalCuentas; ++j) {
            cuenta = cuentasCliente.cuenta[j];

            write(fd, cuenta.numero, sizeof(char) * strlen(cuenta.numero));
            write(fd, "\n", sizeof(char));
            write(fd, cuenta.caducidad, sizeof(char) * strlen(cuenta.caducidad));
            write(fd, "\n", sizeof(char));
            write(fd, cuenta.codigoSeguridad, sizeof(char) * strlen(cuenta.codigoSeguridad));
            write(fd, "\n", sizeof(char));
            write(fd, cuenta.caducidad, sizeof(char) * strlen(cuenta.caducidad));
            write(fd, "\n", sizeof(char));

            strcpy(numCuenta, cuenta.iban.identificadorPais);
            strcat(numCuenta, cuenta.numero);
            write(fd, numCuenta, sizeof(char) * strlen(numCuenta));
            write(fd, "\n", sizeof(char));

            strcpy(swiftCompleto, cuenta.swift.codigoIdentidad);
            strcat(swiftCompleto, cuenta.swift.identificadorPais);
            strcat(swiftCompleto, cuenta.swift.codigoLocalidad);
            strcat(swiftCompleto, cuenta.swift.codigoOficina);
            write(fd, swiftCompleto, sizeof(char) * strlen(swiftCompleto));
            write(fd, "\n", sizeof(char));
        }
    }

    close(fd);

    return 0;
}