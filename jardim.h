//
// Created by GoodBarber on 22/10/2025.
//

#ifndef TRABALHO_JARDIM_H
#define TRABALHO_JARDIM_H
#include "solo.h"
#include "Settings.h"
#include <iostream>

class Jardineiro;

class Jardim {
    int linhas;
    int colunas;
    Solo** grelha;
    Jardineiro* jardineiro;
    int instanteAtual;

public:
    Jardim(int l, int c);
    ~Jardim();

    void imprime() const;
    void avancarInstante(int n = 1);
    bool coordenadaValida(int l, int c) const;
    Solo* getSolo(int l, int c);

    void plantar(int l, int c, Planta* p);
    void colher(int l, int c);
};

#endif //TRABALHO_JARDIM_H