//
// Created by GoodBarber on 01/01/2026.
//

#include "CmdUsar.h"
#include "./Jogo.h"

CmdUsar::CmdUsar(char l, char c)
    : l(l), c(c) {}

bool CmdUsar::executar(Jogo& jogo) {
    jogo.usar(l, c);
    return true;
}
