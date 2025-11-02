//
// Created by GoodBarber on 01/11/2025.
//

#ifndef TRABALHO_ERVADANINHA_H
#define TRABALHO_ERVADANINHA_H

#include "../planta/planta.h"
#include "../../Settings.h"
#include <iostream>

class ErvaDaninha : public Planta {
    int idade;             // quantos instantes já viveu
    int instantesDesdeUltimaMultiplicacao;

public:
    ErvaDaninha();

    void atualiza(Jardim& jardim, int linha, int coluna) override;
    void morrer(Solo& solo) override;
};

#endif //TRABALHO_ERVADANINHA_H