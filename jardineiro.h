//
// Created by GoodBarber on 22/10/2025.
//

#ifndef TRABALHO_JARDINEIRO_H
#define TRABALHO_JARDINEIRO_H

class Jardineiro {
    int linha;
    int coluna;
public:
    Jardineiro(int l=0, int c=0) : linha(l), coluna(c) {}
    bool estaNaPosicao(int l, int c) const { return l == linha && c == coluna; }
};

#endif //TRABALHO_JARDINEIRO_H