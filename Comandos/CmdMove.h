//
// Created by diogo on 23/12/2025.
//

#ifndef TRABALHO_CMDMOVE_H
#define TRABALHO_CMDMOVE_H
#include "Comando.h"


class CmdMove : public Comando{
    char dir;
    public:
    explicit CmdMove(char dir);
    bool executar(Jogo& jogo) override;
};


#endif //TRABALHO_CMDMOVE_H