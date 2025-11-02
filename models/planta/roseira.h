//
// Created by GoodBarber on 01/11/2025.
//

#ifndef TRABALHO_ROSEIRA_H
#define TRABALHO_ROSEIRA_H

#include "../planta/planta.h"
#include "../../Settings.h"
#include <iostream>

class Roseira : public Planta {
public:
    Roseira();

    void atualiza(Jardim& jardim, int linha, int coluna) override;
    void morrer(Solo& solo) override;
};

#endif //TRABALHO_ROSEIRA_H