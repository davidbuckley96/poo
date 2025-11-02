//
// Created by GoodBarber on 02/11/2025.
//

#include "adubo.h"
#include <iostream>

Adubo::Adubo()
    : Ferramenta('a'),
      quantidadeRestante(Settings::Adubo::capacidade) {}

void Adubo::usar(Solo& solo) {
    if (!ativa) {
        std::cout << "O pacote de adubo já está vazio e não pode mais ser usado.\n";
        return;
    }

    if (quantidadeRestante < Settings::Adubo::dose) {
        std::cout << "O pacote de adubo ficou vazio e foi levado pelo vento!\n";
        ativa = false;
        delete this;  // pacote voa embora
        return;
    }

    // Aumenta os nutrientes do solo e reduz a quantidade de adubo
    solo.addNutrientes(Settings::Adubo::dose);
    quantidadeRestante -= Settings::Adubo::dose;

    std::cout << "Adubo usado! +" << Settings::Adubo::dose
              << " nutrientes adicionados ao solo. "
              << "Quantidade restante: " << quantidadeRestante << "\n";

    if (quantidadeRestante <= 0) {
        std::cout << "O pacote de adubo ficou vazio e foi levado pelo vento!\n";
        ativa = false;
        delete this;
    }
}

void Adubo::mostrarInfo() const {
    std::cout << "Adubo (Nº " << getNumeroSerie()
              << ") - Restante: " << quantidadeRestante
              << (estaAtiva() ? " [ativo]" : " [vazio]") << "\n";
}
