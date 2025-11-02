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


    l = linhas;
    c = colunas;

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

void Comandos::listaPropriedades() {

}

void Comandos::verSolo(string& linha, string& coluna, int raio) {

    char lh = tolower(linha[0]);
    char ch = tolower(coluna[0]);

    int l = lh - 'a';
    int c = ch - 'a';

    Solo* s = jardim->getSolo(l, c);
    if (s == nullptr) {
        return;
    }


}

void Comandos::listaFerramentas() {

}

void Comandos::colhe(string& linha, string& coluna) {

    char lh = tolower(linha[0]);
    char ch = tolower(coluna[0]);

    int l = lh - 'a';
    int c = ch - 'a';

    jardim->colher(l,c);
}

void Comandos::planta() {

}

void Comandos::larga() {

}

void Comandos::pega() {

}

void Comandos::compra() {

}

void Comandos::desloca(string direção) {

    char dir = tolower(direção[0]);

    switch (dir) {
        case 'e' : cout << "Movimento esquerdo";
        case 'd' : cout << "Movimento direito";
        case 'c' : cout << "Movimento cima";
        case 'b' : cout << "Movimento baixo";
    }
}

void Comandos::entra() {

}

void Comandos::sai() {

}

void Comandos::grava() {

}

void Comandos::recupera() {

}

void Comandos::apaga() {

}

void Comandos::executa() {

}

void Comandos::fim() {

}






