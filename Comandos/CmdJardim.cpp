//
// Created by diogo on 24/12/2025.
//

#include "CmdJardim.h"

bool CmdJardim::executar(Jogo &jogo) {

    if (jogo.criaJardim(linhas, colunas)) {
        jogo.imprime();
    }
    return true;
}
