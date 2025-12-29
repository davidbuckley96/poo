//
// Created by GoodBarber on 22/10/2025.
//

#ifndef TRABALHO_JARDIM_H
#define TRABALHO_JARDIM_H
#include "../solo/solo.h"
#include "../../Settings.h"
#include <iostream>

class Jardineiro;

class Jardim {
    int linhas;
    int colunas;
    Solo** grelha;
    Jardineiro* jardineiro = nullptr;
    int instanteAtual;

public:
    Jardim(int l, int c);
    Jardim(int l, int c, Jardineiro* j);
    ~Jardim();
    Jardim(const Jardim& outro);
    Jardim& operator=(const Jardim& outro);

    void imprime() const;
    void avancarInstante(int n = 1);
    bool coordenadaValida(int l, int c) const;
    Solo& getSolo(int l, int c);
    int getLinhas() const { return linhas; }
    int getColunas() const { return colunas; }

    void plantar(int l, int c, Planta* p);
    void colher(int l, int c);
    void apanhaFerramenta(Jardineiro& j);
    void colocaFerramentaAleatoria();
    Ferramenta* criaFerramentaAleatoria();


};

#endif //TRABALHO_JARDIM_H