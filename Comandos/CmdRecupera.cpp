//
// Created by diogo on 29/12/2025.
//

#include "CmdRecupera.h"


bool CmdRecupera::executar(Jogo& jogo) {

    jogo.recupera(nome);
    return true;
}