//
// Created by diogo on 29/12/2025.
//

#ifndef TRABALHO_CMDLSOLO_H
#define TRABALHO_CMDLSOLO_H
#include "Comando.h"


class CmdLSolo : public Comando {
    private:
    char l, c;
    int raio;

    public:
    CmdLSolo(char l, char c, int raio) : l(l), c(c), raio(raio) {}
    bool executar(Jogo &jogo) override;
};


#endif //TRABALHO_CMDLSOLO_H