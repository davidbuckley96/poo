//
// Created by GoodBarber on 02/11/2025.
//

#ifndef TRABALHO_CARRODEMAO_H
#define TRABALHO_CARRODEMAO_H

#include "../ferramenta/ferramenta.h"
#include "../../Settings.h"
#include "../solo/solo.h"
#include "../jardim/jardim.h"
#include "../jardineiro/jardineiro.h"
#include <iostream>
#include <cmath>

class CarroDeMao : public Ferramenta {
public:
    CarroDeMao();

    void usar(Solo& solo) override;
    void moverPlanta(Jardim& jardim, Jardineiro& jardineiro,
                     int origemL, int origemC, int destinoL, int destinoC);
    void mostrarInfo() const override;
};

#endif //TRABALHO_CARRODEMAO_H