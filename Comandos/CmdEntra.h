//
// Created by diogo on 26/12/2025.
//

#ifndef TRABALHO_CMDENTRA_H
#define TRABALHO_CMDENTRA_H
#include "Comando.h"


class CmdEntra : public Comando{
    char linha;
    char coluna;

    public:
    CmdEntra(char l, char c);
    bool executar(Jogo& jogo) override;
};


#endif //TRABALHO_CMDENTRA_H