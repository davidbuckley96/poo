//
// Created by diogo on 29/12/2025.
//

#include "CmdCompra.h"

bool CmdCompra::executar(Jogo &jogo) {
    jogo.compra(tipo);
    return true;
}
