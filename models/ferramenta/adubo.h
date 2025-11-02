//
// Created by GoodBarber on 02/11/2025.
//

#ifndef TRABALHO_ADUBO_H
#define TRABALHO_ADUBO_H

#include "../ferramenta/ferramenta.h"
#include "../../Settings.h"
#include "../solo/solo.h"
#include <iostream>

class Adubo : public Ferramenta {
    int quantidadeRestante;

public:
    Adubo();

    void usar(Solo& solo) override;
    void mostrarInfo() const override;
};

#endif //TRABALHO_ADUBO_H