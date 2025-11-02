//
// Created by GoodBarber on 22/10/2025.
//

#include "../jardim/jardim.h"
#include "../solo/solo.h"
#include "../planta/planta.h"
#include "../jardineiro/jardineiro.h"
#include <cstdlib>
#include <iostream>

Jardim::Jardim(int l, int c): linhas(l), colunas(c), jardineiro(nullptr), instanteAtual(0) {
    if (l <= 0 || l > 26 || c <= 0 || c > 26) {
        std::cerr << "Tamanho inválido para jardim (máximo 26x26)." << std::endl;
        std::exit(1);
    }

    grelha = new Solo*[linhas];
    for (int i=0; i < linhas; ++i) {
        grelha[i] = new Solo[colunas];
    }
}

Jardim::~Jardim() {
    for (int i=0; i < linhas; ++i)
        delete[] grelha[i];
    delete[] grelha;
}

bool Jardim::coordenadaValida(int l, int c) const {
    return (l >= 0 && l < linhas && c >= 0 && c < colunas);
}

Solo& Jardim::getSolo(int l, int c) {
    if (!coordenadaValida(l, c)) {
        std::cout << "Coordenada inválida (" << l + 1 << "," << c + 1 << ")" << std::endl;
        std::exit(1);
    }
    return grelha[l][c];
}

void Jardim::imprime() const {
    std::cout << " ";
    for (int c = 0; c < colunas; ++c)
        std::cout << (char)('A' + c) << " ";
    std::cout << "\n";

    for (int l = 0; l < linhas; ++l) {
        std::cout << (char)('A' + l) << " ";
        for (int c = 0; c < colunas; ++c) {
            char ch = ' ';
            if (jardineiro && jardineiro->estaNaPosicao(l, c))
                ch = '*';
            else
                ch = grelha[l][c].getCharRepr();
            std::cout << ch ;
        }
        std::cout << "\n";
    }
}

void Jardim::avancarInstante(int n) {
    for (int i = 0; i < n; ++i) {
        instanteAtual++;

        // FUTURAMENTE: atualizar elementos (plantas, solo, ferramentas...)

        std::cout << "\n--- INSTANTE " << instanteAtual << " ---\n";
        imprime();
    }
}

void Jardim::plantar(int l, int c, Planta *p) {
    if (!coordenadaValida(l, c)) return;

    Solo& s = grelha[l][c];
    if (s.getPlanta() == nullptr) {
        s.setPlanta(p);
        std::cout << "Planta adicionada em " << (char)('A' + l) << (char)('A' + c) << ".\n";
    } else {
        std::cout << "Já existe uma planta nessa posição.\n";
    }
}

void Jardim::colher(int l, int c) {
    if (!coordenadaValida(l, c)) {
        std::cout << "Cordenada Invalida\n";
        return;
    }


    Solo& s = grelha[l][c];
    if (s.getPlanta()) {
        delete s.getPlanta();
        s.setPlanta(nullptr);
        std::cout << "Planta colhida em " << (char)('A' + l) << (char)('A' + c) << ".\n";
    } else {
        std::cout << "Nenhuma planta para colher.\n";
    }
}
