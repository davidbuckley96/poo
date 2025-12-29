//
// Created by diogo on 23/12/2025.
//

#ifndef TRABALHO_CMDAVANCA_H
#define TRABALHO_CMDAVANCA_H
#include "Comando.h"

using namespace std;

class CmdAvanca : public Comando {
    private:
        int n; //numero de instantes a avancar
    public:
        explicit CmdAvanca(int n = 1);
        bool executar(Jogo& jogo) override;
};


#endif //TRABALHO_CMDAVANCA_H