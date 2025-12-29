//
// Created by diogo on 29/12/2025.
//

#ifndef TRABALHO_CMDAPAGA_H
#define TRABALHO_CMDAPAGA_H
#include "Comando.h"


class CmdApaga : public Comando {
    std::string nome;
public:
    explicit CmdApaga(std::string nome) : nome(nome) {}
    bool executar(Jogo& jogo) override;
};


#endif //TRABALHO_CMDAPAGA_H