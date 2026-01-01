//
// Created by GoodBarber on 01/01/2026.
//

#ifndef TRABALHO_CMDUSAR_H
#define TRABALHO_CMDUSAR_H

#include "Comando.h"

class CmdUsar : public Comando {
    char l, c;
public:
    CmdUsar(char l, char c);
    bool executar(Jogo& jogo) override;
};


#endif //TRABALHO_CMDUSAR_H