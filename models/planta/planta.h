//
// Created by GoodBarber on 22/10/2025.
//

#ifndef TRABALHO_PLANTA_H
#define TRABALHO_PLANTA_H

#include "../../Settings.h"
#include <string>
#include <iostream>

class Solo;   // Declaração antecipada
class Jardim;

class Planta {
protected:
    int agua;
    int nutrientes;
    bool viva;
    std::string beleza;
    char simbolo;

public:
    Planta(char simb, const std::string& tipoBeleza);
    virtual ~Planta();

    bool estaViva() const;
    int getAgua() const;
    int getNutrientes() const;
    const std::string& getBeleza() const;
    char getCharRepr() const;

    void addAgua(int q);
    void addNutrientes(int q);

    // Função polimórfica chamada a cada instante
    virtual void atualiza(Jardim& jardim, int linha, int coluna) = 0;

    // Método chamado quando a planta morre
    virtual void morrer(Solo& solo);

    // Impressão genérica
    virtual void mostrarInfo() const;
};

#endif //TRABALHO_PLANTA_H