#include <stdio.h>
#include "funciones.h"
#include "models/banco.h"
#include "tools/reader.h"
#include "tools/interfaz.h"

int main(int argc, char *argv[]) {
    if (errorArgumentos(argc, argv, 3) == 1) {
        return 1;
    }

    // Obtenemos el nombre de los ficheros por parametro
    char *clientesFileName = (char *) malloc(strlen(argv[1]));
    strcpy(clientesFileName, argv[1]);

    char *cuentasFileName = (char *) malloc(strlen(argv[2]));
    strcpy(cuentasFileName, argv[2]);

    // Inizializar
    Banco * banco;
    banco = malloc(sizeof(Banco));
    banco->cuentas = NULL;
    banco->clientes = NULL;
    banco->totalCuentas = 0;
    banco->totalClientes = 0;

    // Guardamos los datos de los ficheros en el objeto banco
    leerClientes(clientesFileName, banco);
    leerCuentas(cuentasFileName, banco);

    int salir;
    do{
        salir = mostrarMenuPrincipal(banco);
    }while (salir==1);


    return 0;
}