//
// Created by diogo on 29/12/2025.
//

#ifndef TRABALHO_CMDEXECUTA_H
#define TRABALHO_CMDEXECUTA_H
#include "Comando.h"
#include "Interface/Interface.h"

class CmdExecuta : public Comando{
        private:
                std::string nF;
                Interface* interface;
        public:
                CmdExecuta(const string nomeFicheiro, Interface* i) : nF(nomeFicheiro), interface(i) {}
                bool executar(Jogo &jogo) override;
};


#endif //TRABALHO_CMDEXECUTA_H