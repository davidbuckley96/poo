//
// Created by diogo on 29/12/2025.
//

#include "CmdApaga.h"

bool CmdApaga::executar(Jogo &jogo) {

    jogo.apaga(nome);
    return true;
}
