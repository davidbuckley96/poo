//
// Created by diogo on 29/12/2025.
//

#include "CmdPlanta.h"

bool CmdPlanta::executar(Jogo &jogo) {
    jogo.planta(l, c, tipo);
    return true;
}

