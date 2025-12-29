//
// Created by diogo on 29/12/2025.
//

#ifndef TRABALHO_CMDCOMPRA_H
#define TRABALHO_CMDCOMPRA_H
#include "Comando.h"


class CmdCompra : public Comando{
    char tipo;
public:
    explicit CmdCompra(char tipo) : tipo(tipo) {}
    bool executar(Jogo& jogo) override;
};


#endif //TRABALHO_CMDCOMPRA_H