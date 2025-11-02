//
// Created by GoodBarber on 01/11/2025.
//
#include "../ferramenta/ferramenta.h"
#include "../solo/solo.h"
#include <iostream>

int Ferramenta::proximoNumero = 1;

Ferramenta::Ferramenta(char s)
    : simbolo(s), ativa(true)
{
    numeroSerie = proximoNumero++;
}

Ferramenta::~Ferramenta() = default;

int Ferramenta::getNumeroSerie() const {
    return numeroSerie;
}

char Ferramenta::getCharRepr() const {
    return simbolo;
}

bool Ferramenta::estaAtiva() const {
    return ativa;
}

void Ferramenta::mostrarInfo() const {
    std::cout << "Ferramenta " << simbolo
              << " (Nº " << numeroSerie << ")"
              << (ativa ? " [ativa]" : " [inativa]") << "\n";
}
