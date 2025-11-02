//
// Created by GoodBarber on 02/11/2025.
//

#ifndef TRABALHO_PLANTAEXOTICA_H
#define TRABALHO_PLANTAEXOTICA_H

#include "../planta/planta.h"
#include "../../Settings.h"
#include <iostream>

/**
 * PlantaExótica: planta de vida curta e multiplicação rápida.
 * - Começa com 10 de água e 5 de nutrientes.
 * - Absorve 1 água e 1 nutriente do solo por instante.
 * - Multiplica-se em até 2 posições vizinhas se água < 30 e não houver Erva Daninha.
 * - Morre após 3 instantes ou se água > 40.
 * - Representada por 'x' no jardim.
 */

class PlantaExotica : public Planta {
    int idade; // quantos instantes já viveu

public:
    PlantaExotica();

    void atualiza(Jardim& jardim, int linha, int coluna) override;
    void morrer(Solo& solo) override;
};

#endif //TRABALHO_PLANTAEXOTICA_H