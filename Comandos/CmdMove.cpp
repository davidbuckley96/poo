//
// Created by diogo on 23/12/2025.
//

#include "CmdMove.h"
#include <iostream>

CmdMove::CmdMove(char dir) : dir(dir) {}

bool CmdMove::executar(Jogo& jogo) {
    jogo.mover(dir);
    return true;
}
