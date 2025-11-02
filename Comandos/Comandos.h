//
// Created by diogo on 01/11/2025.
//

#ifndef TRABALHO_COMANDOS_H
#define TRABALHO_COMANDOS_H


#include "../models/jardim/jardim.h"

using namespace std;

class Comandos {
    private:
    Jardim* jardim;
    bool jardimCriado;


    public:
    void criaJardim(int linhas, int colunas);
    Comandos();
    ~Comandos();
    bool existeJardim() const;
    void avancaTempo(int n);
    void listaPlantas();
    void listaPlanta(const string& linhas, const string& colunas);
};


#endif //TRABALHO_COMANDOS_H