//
// Created by diogo on 29/12/2025.
//

#ifndef TRABALHO_CMDRECUPERA_H
#define TRABALHO_CMDRECUPERA_H
#include "Comando.h"


class CmdRecupera : public Comando {
    std::string nome;
public:
    explicit CmdRecupera(std::string nome) : nome(nome) {}
    bool executar(Jogo& jogo) override;
};


#endif //TRABALHO_CMDRECUPERA_H