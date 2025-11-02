//
// Created by GoodBarber on 02/11/2025.
//

#ifndef TRABALHO_REGADOR_H
#define TRABALHO_REGADOR_H

#include "../ferramenta/ferramenta.h"
#include "../../Settings.h"
#include "../solo/solo.h"
#include <iostream>

class Regador : public Ferramenta {
    int aguaRestante;

public:
    Regador();

    void usar(Solo& solo) override;
    void mostrarInfo() const override;
};

#endif //TRABALHO_REGADOR_H