//
// Created by GoodBarber on 22/10/2025.
//

#include "solo.h"
#include <cstdlib>
#include <ctime>

Solo::Solo() {
    agua = Settings::Jardim::agua_min +
        rand() % (Settings::Jardim::agua_max - Settings::Jardim::agua_min + 1);

    nutrientes = Settings::Jardim::nutrientes_min +
        rand() % (Settings::Jardim::nutrientes_max - Settings::Jardim::nutrientes_min + 1);

    planta = nullptr;
    ferramenta = nullptr;
}

Solo::~Solo() {}  // responsabilidade de apagar passa para o jardim
int Solo::getAgua() const {return agua;}
int Solo::getNutrientes() const {return nutrientes;}
Planta* Solo::getPlanta() const {return planta;}
Ferramenta* Solo::getFerramenta() const {return ferramenta;}
void Solo::setPlanta(Planta* p) {planta = p;}
void Solo::setFerramenta(Ferramenta* f) {ferramenta = f;}
void Solo::addAgua(int q) {agua += q;}
void Solo::addNutrientes(int q) {nutrientes += q;}
char Solo::getCharRepr() const {
    if (planta) return 'P';
    if (ferramenta) return 'F';
    return ' ';
}
