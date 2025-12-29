//
// Created by diogo on 29/12/2025.
//

#include "CmdLSolo.h"

bool CmdLSolo::executar(Jogo &jogo) {
    jogo.lsolo(l, c, raio);
    return true;
}
