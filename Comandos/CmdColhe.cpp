//
// Created by diogo on 29/12/2025.
//

#include "CmdColhe.h"

bool CmdColhe::executar(Jogo &jogo) {
    jogo.colhe(l, c);
    return true;
}
