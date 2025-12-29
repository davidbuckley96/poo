//
// Created by diogo on 29/12/2025.
//

#ifndef TRABALHO_CMDPLANTA_H
#define TRABALHO_CMDPLANTA_H
#include "Comando.h"


class CmdPlanta : public Comando{
    private:
        char l, c;
        char tipo;

    public:
        CmdPlanta(char l, char c, char tipo) : l(l), c(c), tipo(tipo) {}
        bool executar(Jogo &jogo) override;
};


#endif //TRABALHO_CMDPLANTA_H