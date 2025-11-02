//
// Created by GoodBarber on 01/11/2025.
//

#ifndef TRABALHO_CACTO_H
#define TRABALHO_CACTO_H

#include "../planta/planta.h"
#include "../../Settings.h"
#include <iostream>

class Cacto : public Planta {
    int instantesAguaAlta;     // contador de instantes com água > 100
    int instantesNutrientesZero; // contador de instantes com nutrientes == 0

public:
    Cacto();

    void atualiza(Jardim& jardim, int linha, int coluna) override;
    void morrer(Solo& solo) override;
};

#endif //TRABALHO_CACTO_H