//
// Created by diogo on 23/12/2025.
//

#include "CmdAvanca.h"

#include <iostream>

CmdAvanca::CmdAvanca(int n) : n(n) {
    if (this->n <= 0) this->n = 1;
}

bool CmdAvanca::executar(Jogo& jogo) {
    jogo.avancar(n);

    std::cout << "Instante: " << jogo.getInstante() << "\n";

    return true;
}
