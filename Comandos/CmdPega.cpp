//
// Created by diogo on 28/12/2025.
//

#include "CmdPega.h"


CmdPega::CmdPega(int n) : nSerie(n) {}

bool CmdPega::executar(Jogo &jogo) {
    jogo.pega(nSerie);
    return true;
}
