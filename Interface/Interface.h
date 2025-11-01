//
// Created by diogo on 01/11/2025.
//

#ifndef TRABALHO_INTERFACE_H
#define TRABALHO_INTERFACE_H
#include "../jardim.h"
#include "../Comandos/Comandos.h"

using namespace std;

class Interface {
    string comando;
    string nomeComando;
    int linhas,colunas;
    string linhaLetra, colunaLetra;
    Comandos comandos;
    bool stop;

public:
    Interface() = default;
    void inicializa();
    void verificaComando();
private:

};


#endif //TRABALHO_INTERFACE_H