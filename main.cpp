#include <iostream>

#include "Interface/Interface.h"

int main() {
    Interface ui;
    ui.inicializa();
    srand(time(nullptr));  // <-- (TEMPORÁRIO): Inicializa o gerador de números aleatórios para funcionamento do valor aleatório de água e nutrientes

    return 0;
}