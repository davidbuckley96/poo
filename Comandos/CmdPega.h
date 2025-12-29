//
// Created by diogo on 28/12/2025.
//

#ifndef TRABALHO_CMDPEGA_H
#define TRABALHO_CMDPEGA_H
#include "Comando.h"


class CmdPega : public Comando{
    private:
        int nSerie;

    public:
    CmdPega(int n);
    bool executar(Jogo &jogo) override;
};


#endif //TRABALHO_CMDPEGA_H