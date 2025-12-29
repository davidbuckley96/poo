//
// Created by diogo on 23/12/2025.
//

#ifndef TRABALHO_COMANDO_H
#define TRABALHO_COMANDO_H
#include "Jogo.h"


class Comando {
    public:
        virtual ~Comando() {};
        virtual bool executar(Jogo& jogo) = 0;
};


#endif //TRABALHO_COMANDO_H