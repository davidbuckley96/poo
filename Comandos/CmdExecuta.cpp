//
// Created by diogo on 29/12/2025.
//

#include "CmdExecuta.h"
#include <sstream>


bool CmdExecuta::executar(Jogo &jogo) {

    interface->executaFicheiro(nF);
    return true;
}
