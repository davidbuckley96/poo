//
// Created by diogo on 29/12/2025.
//

#ifndef TRABALHO_CMDLPLANTAS_H
#define TRABALHO_CMDLPLANTAS_H
#include "Comando.h"



class CmdLPlantas : public Comando{
    public:
        bool executar(Jogo &jogo) override;
};


#endif //TRABALHO_CMDLPLANTAS_H