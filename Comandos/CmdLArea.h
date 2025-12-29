//
// Created by diogo on 29/12/2025.
//

#ifndef TRABALHO_CMDLAREA_H
#define TRABALHO_CMDLAREA_H
#include "Comando.h"


class CmdLArea : public Comando{
    public:
    bool executar(Jogo &jogo) override;
};


#endif //TRABALHO_CMDLAREA_H