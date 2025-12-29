//
// Created by diogo on 29/12/2025.
//

#include "CmdLPlanta.h"

bool CmdLPlanta::executar(Jogo &jogo) {
    jogo.lplanta(l, c);
    return true;
}
