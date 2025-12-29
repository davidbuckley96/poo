//
// Created by diogo on 01/11/2025.
//

#ifndef TRABALHO_INTERFACE_H
#define TRABALHO_INTERFACE_H
#include <string>
#include "Jogo.h"

class Comando;
using namespace std;

class Interface {
private:

    bool processaLinha(const string &linha);
    Comando* criarComando(const string &comando, stringstream& ss);
    Jogo jogo;

public:
    void run();
    bool executaFicheiro(const std::string& nomeFicheiro);
};


#endif //TRABALHO_INTERFACE_H