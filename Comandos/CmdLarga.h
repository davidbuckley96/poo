//
// Created by diogo on 28/12/2025.
//

#ifndef TRABALHO_CMDLARGA_H
#define TRABALHO_CMDLARGA_H
#include "Comando.h"


class CmdLarga : public Comando {
    bool executar(Jogo &jogo) override;
};


#endif //TRABALHO_CMDLARGA_H