//
// Created by GoodBarber on 01/01/2026.
//

#ifndef TRABALHO_CMDUSAR_H
#define TRABALHO_CMDUSAR_H

#include "Comando.h"

class CmdUsar : public Comando {
    bool temDestino = false;
    char l1, c1;
    char l2, c2;
public:
    CmdUsar(char l, char c);
    CmdUsar(char lOrig, char cOrid, char lDest, char cDest);
    bool executar(Jogo& jogo) override;
};


#endif //TRABALHO_CMDUSAR_H