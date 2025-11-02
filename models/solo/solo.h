//
// Created by GoodBarber on 22/10/2025.
//

#ifndef TRABALHO_SOLO_H
#define TRABALHO_SOLO_H
#include "../../Settings.h"

class Planta;
class Ferramenta;

class Solo {
    int agua;
    int nutrientes;
    Planta* planta;
    Ferramenta* ferramenta;

public:
    Solo();
    ~Solo();

    int getAgua() const;
    int getNutrientes() const;
    Planta* getPlanta() const;
    Ferramenta* getFerramenta() const;

    void setPlanta(Planta* p);
    void setFerramenta(Ferramenta* f);

    void addAgua(int q);
    void addNutrientes(int q);

    char getCharRepr() const;  // Caractere que representa o solo
};

#endif //TRABALHO_SOLO_H