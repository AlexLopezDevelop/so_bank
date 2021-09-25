//
// Created by Alex Lopez on 24/9/21.
//

#include "interfaz.h"

void guardarInfoBanco(Banco *banco) {

    display("\nRealizando copia de seguridad");
    if (realizarBackup(banco)) {
        display("\nError al ralizar la copia de seguridad");
    } else {
        display("\nCopia de seguridad realizada correctamente\n");
    }

}

void mostrarInfoCuenta(Banco *banco) {
    char cuentaBanco[30];
    int introducido;

    display("\nIdentificador del cliente: ");
    read(0, cuentaBanco, 30);
    introducido = atoi(cuentaBanco);

    Cuenta cuenta = obtenerCuentaPorId(banco, introducido);

    display("\nNúmero de cuenta: ");
    display(cuenta.numero);
    display("\nFecha de caducidad de la tarjeta: ");
    display(cuenta.caducidad);
    display("\nCódigo de seguridad de la tarjeta: ");
    display(cuenta.codigoSeguridad);
    display("\nIBAN: ");
    display(cuenta.iban.identificadorPais);
    display(cuenta.iban.digitosControl);
    display(cuenta.iban.numeroDeCuenta);
    display("\nBIC/SWIFT: ");
    display(cuenta.swift.codigoIdentidad);
    display(cuenta.swift.identificadorPais);
    display(cuenta.swift.codigoLocalidad);
    display(cuenta.swift.codigoOficina);
    display("\n");
}

void mostrarInfoCliente(Banco *banco) {
    char totalCuentas[100];
    char idCliente[30];
    int introducido;


    display("\nIdentificador del cliente: ");
    read(0, idCliente, 30);
    introducido = atoi(idCliente);

    Cliente cliente = obtenerClientePorId(banco, introducido);
    CuentasCliente cuentasCliente = obtenerCuentaPorIdCliente(banco, introducido);

    display("\nIdentificador del cliente: ");
    display(cliente.identificador);
    display("\nNombre del titular de la cuenta bancaria: ");
    display(cliente.nombre);
    display("\nTeléfono: ");
    display(cliente.telefono);

    display("\nNumero de cuentas: ");
    sprintf(totalCuentas, "%d", cuentasCliente.totalCuentas);
    display(totalCuentas);
    display("\n");

    Cuenta cuenta;
    for (int i = 0; i < cuentasCliente.totalCuentas; ++i) {
        cuenta = cuentasCliente.cuenta[i];
        display("\nNúmero de cuenta: ");
        display(cuenta.numero);
        display("\nFecha de caducidad de la tarjeta: ");
        display(cuenta.caducidad);
        display("\nCódigo de seguridad de la tarjeta: ");
        display(cuenta.codigoSeguridad);
        display("\nIBAN: ");
        display(cuenta.iban.identificadorPais);
        display(cuenta.iban.digitosControl);
        display(cuenta.iban.numeroDeCuenta);
        display("\nBIC/SWIFT: ");
        display(cuenta.swift.codigoIdentidad);
        display(cuenta.swift.identificadorPais);
        display(cuenta.swift.codigoLocalidad);
        display(cuenta.swift.codigoOficina);
        display("\n");
    }


    // TODO: Refactor para que sea contante la data y no consultar cada vez
    //cliente->cuentasCliente = malloc(sizeof (CuentasCliente) * cuentasCliente->totalCuentas);
    //cliente->cuentasCliente = cuentasCliente;

}

int mostrarMenuPrincipal(Banco *banco) {
    char opcionUsuario[30];
    int opcion;

    display("\n----------------- Andorra Bank -----------------\n\n");
    display("1. Muestra la informacion de un cliente\n");
    display("2. Muestra la informacion de una cuenta\n");
    display("3. Guarda toda la informacion en un fichero\n");
    display("4. Salir\n\n");
    display("Opcion: ");
    // TODO: fix readInput
    read(0, opcionUsuario, 30);

    opcion = atoi(opcionUsuario);

    if (opcion <= 4 && opcion > 0) {
        switch (opcion) {
            case 1:
                mostrarInfoCliente(banco);
                break;
            case 2:
                mostrarInfoCuenta(banco);
                break;
            case 3:
                display("3");
                guardarInfoBanco(banco);
                break;
            case 4:
                return 0;
                break;
        }
    } else {
        display("Error esta opcion no existe");
    }
    return 1;
}

