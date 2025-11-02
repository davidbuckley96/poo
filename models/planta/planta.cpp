//
// Created by GoodBarber on 01/11/2025.
//

#include "../planta/planta.h"
#include "../solo/solo.h"
#include "../jardim/jardim.h"
#include <iostream>

Planta::Planta(char simb, const std::string& tipoBeleza)
    : agua(0), nutrientes(0), viva(true), beleza(tipoBeleza), simbolo(simb)
{
}

Planta::~Planta() = default;

bool Planta::estaViva() const {
    return viva;
}

int Planta::getAgua() const {
    return agua;
}

int Planta::getNutrientes() const {
    return nutrientes;
}

const std::string& Planta::getBeleza() const {
    return beleza;
}

char Planta::getCharRepr() const {
    return simbolo;
}

void Planta::addAgua(int q) {
    agua += q;
    if (agua < 0) agua = 0;
}

void Planta::addNutrientes(int q) {
    nutrientes += q;
    if (nutrientes < 0) nutrientes = 0;
}

void Planta::morrer(Solo& solo) {
    if (!viva) return;
    viva = false;
    solo.addAgua(agua / 2);
    solo.addNutrientes(nutrientes / 2);
    std::cout << "Uma planta " << beleza << " (" << simbolo << ") morreu.\n";
}

void Planta::mostrarInfo() const {
    std::cout << "Planta '" << simbolo << "' | Agua: " << agua
              << " | Nutrientes: " << nutrientes
              << " | Beleza: " << beleza
              << " | Estado: " << (viva ? "viva" : "morta") << "\n";
}
