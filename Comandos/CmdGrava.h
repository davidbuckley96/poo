//
// Created by diogo on 29/12/2025.
//

#ifndef TRABALHO_CMDGRAVA_H
#define TRABALHO_CMDGRAVA_H
#include <string>

#include "Comando.h"


class CmdGrava : public Comando {
    std::string nome;
public:
    explicit CmdGrava(std::string nome) : nome(nome) {}
    bool executar(Jogo& jogo) override;
};


#endif //TRABALHO_CMDGRAVA_H