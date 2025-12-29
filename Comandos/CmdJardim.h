//
// Created by diogo on 24/12/2025.
//

#ifndef TRABALHO_CMDJARDIM_H
#define TRABALHO_CMDJARDIM_H
#include "Comando.h"


class CmdJardim : public Comando{
    int linhas;
    int colunas;

    public:
    CmdJardim(int l, int c) : linhas(l), colunas(c) {}
    bool executar(Jogo& jogo) override;
};


#endif //TRABALHO_CMDJARDIM_H