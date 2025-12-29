//
// Created by diogo on 28/12/2025.
//

#ifndef TRABALHO_CMDLFERR_H
#define TRABALHO_CMDLFERR_H
#include "Comando.h"


class CmdLFerr : public Comando{
    bool executar(Jogo &jogo) override;
};


#endif //TRABALHO_CMDLFERR_H