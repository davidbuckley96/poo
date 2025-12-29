//
// Created by diogo on 23/12/2025.
//

#ifndef TRABALHO_CMDFIM_H
#define TRABALHO_CMDFIM_H
#include "Comando.h"


class CmdFim : public Comando{
    public:
        bool executar(Jogo& jogo) override;
};


#endif //TRABALHO_CMDFIM_H