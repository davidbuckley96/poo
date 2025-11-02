//
// Created by diogo on 01/11/2025.
//

#include "Comandos.h"

using namespace std;

Comandos::Comandos() {
    jardim = nullptr;
    jardimCriado = false;
}

Comandos::~Comandos() {
    delete jardim;
}

bool Comandos::existeJardim() const {
    return jardimCriado;
}

void Comandos::criaJardim(int linhas, int colunas) {

    if (linhas < 1 || linhas > 26 || colunas < 1 || colunas > 26) {
        std::cout << "Dimensões inválidas. Use valores entre 1 e 26.\n";
        return;
    }

    if (jardimCriado) {
        cout << "O jardim já foi criado e não pode ser recriado.\n";
        return;
    }

    if (jardim != nullptr) {
        delete jardim;
        jardim = nullptr;
    }



    jardim = new Jardim(linhas, colunas);
    jardimCriado = true;


    cout << "Jardim criado com sucesso (" << linhas << "x" << colunas << ").\n";
    jardim->imprime();

}

void Comandos::avancaTempo(int n) {

    jardim->avancarInstante(n);
    jardim->imprime();
}

void Comandos::listaPlantas() {

}

void Comandos::listaPlanta(const string& linhas, const string& colunas) {

}

// void Comandos::
