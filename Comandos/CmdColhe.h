//
// Created by diogo on 29/12/2025.
//

#ifndef TRABALHO_CMDCOLHE_H
#define TRABALHO_CMDCOLHE_H
#include "Comando.h"


class CmdColhe : public Comando {
    private:
        char l, c;
    public:
        CmdColhe(char l, char c) : l(l), c(c){}
        bool executar(Jogo &jogo) override;
};


#endif //TRABALHO_CMDCOLHE_H