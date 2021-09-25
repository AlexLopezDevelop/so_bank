#include "funciones.h"

// ----------------------------------  FREE Y APUNTAR A NULL  ----------------------------------
void liberarMemoria(void *ptr) {
    // Libermaos Memoria
    free(ptr);
    // Dejamos apuntando a NULL
    ptr = NULL;
}

// ----------------------------------  CONTROLAR PASO DE ARGUMENTOS  ----------------------------------
int errorArgumentos(int argc, char *argv[], int num_argumentos) {

    if (argc != num_argumentos) {
        display("\nERROR en el numero de ficheros\n");
        return 1;
    } else {
        if (strcmp(argv[1], FILE1) != 0) {
            display("\nERROR el 1er fichero no es correcto\n");
            return 1;
        } else if (strcmp(argv[2], FILE2) != 0) {
            display("\nERROR el 2do fichero no es correcto\n");
            return 1;
        } else {
            display("\nFicheros recibidos correctamente\n");
            return 0;
        }
    }
}

// ----------------------------------  CONTROLAR OBERTURA FICHERO  ----------------------------------
int errorAbrir(int fd, char *nombre_f) {
    char aux[200];

    if (fd < 0) {
        sprintf(aux, "\nERROR al abrir el fichero: %s\n", nombre_f);
        display(aux);
        return 1;
    } else {
        sprintf(aux, "\nEl fichero: %s se ha abierto correctamente\n", nombre_f);
        display(aux);
        return 0;
    }
}

// ----------------------------------  COMPROBAR FINAL DE FICHERO  ----------------------------------
int checkEOF(int fd) {
    int num_bytes;
    char car;

    // Controlamos cuantos bytes retorna la funcion read()
    num_bytes = read(fd, &car, sizeof(char));

    // Si retorna 0bytes porque no hay mas caracteres es el End Of File
    if (num_bytes == 0) {
        return 1;
    }

    // Reposicionamos el puntero a la posicion que acaba de leer
    lseek(fd, -1, SEEK_CUR);

    return 0;
}

// ----------------------------------  LEER CADENA TECLADO  ----------------------------------
void readInput(char **string) {
    int i = 0;
    char caracter = ' ';

    // Bucle para leer caracteres entrados por teclado hasta Enter
    while (caracter != '\n') {
        // Lectura de caracter por caracter
        read(0, &caracter, sizeof(char));

        // TODO: Revisar esta 💩
        // Redimensiona la cadena por cada caracter del usuario
        *string = (char *) realloc(*string, (sizeof(char) * (i + 1)));

        // Asigna el caracter a la cadena
        (*string)[i] = caracter;

        // Cuando el caracter sea un salto de linea (enter) marcamos el fianl de la cadena
        if (caracter == '\n') {
            (*string)[i] = '\0';
        }
        i++;
    }
}

// ----------------------------------  MOSTRAR POR PANTALLA  ----------------------------------
void display(char *string) {
    write(1, string, sizeof(char) * strlen(string));
}

// ----------------------------------  LEER PALABRA FICHERO  ----------------------------------
char *readLineFile(int fd, char hasta) {
    int i = 0;
    char *aux = NULL;
    char caracter = '\0';

    // Bucle para almacenar la cadena hasta el caracter delimitador o cuando sea EOF
    while (caracter != hasta && !checkEOF(fd)) {

        // Leemos un solo caracter (1byte)
        read(fd, &caracter, sizeof(char));

        // Si el caracter es valido reasignamos espacio en la memoria y lo guardamos en la cadena
        if (caracter != hasta) {
            aux = (char *) realloc(aux, i + 1);
            aux[i] = caracter;
            i++;
        }

    }
    // Marcamos el final de la cadena y lo copiamos
    aux[i] = '\0';

    return aux;
}

char *readLineFileByCharacter(int fd, int charactersToRead) {
    char *aux = NULL;
    char caracter = '\0';

    for (int i = 0; i < charactersToRead; ++i) {
        // Leemos un solo caracter (1byte)
        read(fd, &caracter, sizeof(char));

        aux = (char *) realloc(aux, i + 1);
        aux[i] = caracter;
    }

    // Marcamos el final de la cadena y lo copiamos
    aux[strlen(aux)+1] = '\0';

    return aux;
}

// ----------------------------------  GUARDAR LINEA EN FICHERO  ----------------------------------
void guardarLineaEnFichero(char * linea) {

}

// ----------------------------------  CONTROLAR SI UN CARACTER ES NUMERO  ----------------------------------
int esNumero(char car) {
    if (car >= '0' && car <= '9') {
        return 1;
    } else { return 0; }
}

// ----------------------------------  INVERTIR UNA PALABRA  ----------------------------------
char *invertirCadena(char cadena[]) {
    int izquierda, derecha;
    int longitud = strlen(cadena);
    char temporal;

    // Bucle para invertir las casillas
    for (izquierda = 0, derecha = longitud - 1; izquierda < (longitud / 2); izquierda++, derecha--) {
        temporal = cadena[izquierda];
        cadena[izquierda] = cadena[derecha];
        cadena[derecha] = temporal;
    }
    return cadena;
}

// ----------------------------------  MOSTRAR FECHA ----------------------------------
void showDate() {
    time_t now;

    time(&now);
    display(ctime(&now));
}