//
// Created by diogo on 26/12/2025.
//

#ifndef TRABALHO_CMDSAI_H
#define TRABALHO_CMDSAI_H
#include "Comando.h"


class CmdSai : public Comando{
    public:
    bool executar(Jogo& jogo) override;
};


#endif //TRABALHO_CMDSAI_H