//
// Created by GoodBarber on 02/11/2025.
//

#ifndef TRABALHO_TESOURA_H
#define TRABALHO_TESOURA_H

#include "../ferramenta/ferramenta.h"
#include "../../Settings.h"
#include "../solo/solo.h"
#include "../planta/planta.h"
#include <iostream>

class Tesoura : public Ferramenta {
public:
    Tesoura();

    void usar(Solo& solo) override;
    void mostrarInfo() const override;
};

#endif //TRABALHO_TESOURA_H