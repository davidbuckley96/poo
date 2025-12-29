//
// Created by diogo on 26/12/2025.
//

#include "CmdEntra.h"

CmdEntra::CmdEntra(char l, char c) : linha(l), coluna(c) {

}

bool CmdEntra::executar(Jogo &jogo) {

    jogo.entra(linha, coluna);


    return true;
}
