//
// Created by GoodBarber on 02/11/2025.
//

#include "tesoura.h"
#include "../planta/planta.h"
#include "../planta/ervadaninha.h"
#include <typeinfo>
#include <iostream>

Tesoura::Tesoura()
    : Ferramenta('t')
{
    ativa = true; // Tesoura nunca deixa de ser ativa
}

void Tesoura::usar(Solo& solo) {
    if (!ativa) {
        std::cout << "A tesoura está inativa (isso nunca deveria acontecer!).\n";
        return;
    }

    Planta* p = solo.getPlanta();
    if (!p) {
        std::cout << "Nada para podar aqui.\n";
        return;
    }

    // Se a planta for "feia", eliminá-la
    if (p->getBeleza() == "feia") {
        std::cout << "Tesoura de poda em ação! Planta feia eliminada.\n";
        p->morrer(solo);
        solo.setPlanta(nullptr);
    } else {
        std::cout << "A planta aqui é bonita ou neutra, não será cortada.\n";
    }
}

void Tesoura::mostrarInfo() const {
    std::cout << "Tesoura de poda (Nº " << getNumeroSerie() << ") - "
              << "Feita de aço cromado, nunca se desgasta. [sempre ativa]\n";
}
