#include "CmdUsar.h"
#include "./Jogo.h"

CmdUsar::CmdUsar(char l, char c)
    : temDestino(false), l1(l), c1(c), l2(0), c2(0) {}

CmdUsar::CmdUsar(char lOrig, char cOrig, char lDest, char cDest)
    : temDestino(true), l1(lOrig), c1(cOrig), l2(lDest), c2(cDest) {}

bool CmdUsar::executar(Jogo& jogo) {
    if (temDestino)
        jogo.usar(l1, c1, l2, c2);
    else
        jogo.usar(l1, c1);

    return true;
}