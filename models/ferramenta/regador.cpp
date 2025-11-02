//
// Created by GoodBarber on 02/11/2025.
//

#include "regador.h"
#include <iostream>

Regador::Regador()
    : Ferramenta('g'),
      aguaRestante(Settings::Regador::capacidade)
{
}

void Regador::usar(Solo& solo) {
    if (!ativa) {
        std::cout << "O regador está vazio e não pode mais ser usado.\n";
        return;
    }

    // Verifica se ainda há água suficiente
    if (aguaRestante < Settings::Regador::dose) {
        std::cout << "O regador ficou sem água e foi lançado longe!\n";
        ativa = false;  // marca como inativo
        delete this;    // destrói o objeto
        return;
    }

    // Usa o regador: adiciona água ao solo e subtrai do regador
    solo.addAgua(Settings::Regador::dose);
    aguaRestante -= Settings::Regador::dose;

    std::cout << "Regador usado! +" << Settings::Regador::dose
              << " unidades de água adicionadas ao solo. "
              << "Água restante no regador: " << aguaRestante << "\n";

    // Se acabou a água, destrói o objeto
    if (aguaRestante <= 0) {
        std::cout << "O regador ficou vazio e foi lançado longe!\n";
        ativa = false;
        delete this;
    }
}

void Regador::mostrarInfo() const {
    std::cout << "Regador (Nº " << getNumeroSerie()
              << ") - Água restante: " << aguaRestante
              << (estaAtiva() ? " [ativo]" : " [inativo]") << "\n";
}
