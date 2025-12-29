//
// Created by diogo on 29/12/2025.
//

#ifndef TRABALHO_CMDLPLANTA_H
#define TRABALHO_CMDLPLANTA_H
#include "Comando.h"

class CmdLPlanta : public Comando {
    char l, c;
public:
    CmdLPlanta(char l, char c) : l(l), c(c) {}
    bool executar(Jogo& jogo) override;
};


#endif //TRABALHO_CMDLPLANTA_H