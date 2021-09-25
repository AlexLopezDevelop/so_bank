//
// Created by Alex Lopez on 20/9/21.
//

#ifndef LSTARTER_IBAN_H
#define LSTARTER_IBAN_H

typedef struct {
    char identificadorPais[3];
    char digitosControl[3];
    char numeroDeCuenta[17];
}Iban;

#endif //LSTARTER_IBAN_H
