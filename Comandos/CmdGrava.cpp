//
// Created by diogo on 29/12/2025.
//

#include "CmdGrava.h"

bool CmdGrava::executar(Jogo &jogo) {

    jogo.grava(nome);
    return true;
}
