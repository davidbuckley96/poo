//
// Created by GoodBarber on 01/11/2025.
//

#ifndef TRABALHO_FERRAMENTA_H
#define TRABALHO_FERRAMENTA_H

#include "../../Settings.h"
#include <string>
#include <iostream>

class Solo;

class Ferramenta {
protected:
    int numeroSerie;
    char simbolo;
    bool ativa;
    static int proximoNumero;

public:
    Ferramenta(char s);
    virtual ~Ferramenta();

    int getNumeroSerie() const;
    char getCharRepr() const;
    bool estaAtiva() const;

    // Método polimórfico — cada ferramenta implementa sua ação
    virtual void usar(Solo& solo) = 0;
    virtual void mostrarInfo() const;
};

#endif //TRABALHO_FERRAMENTA_H