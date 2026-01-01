//
// Created by GoodBarber on 22/10/2025.
//

#ifndef TRABALHO_JARDINEIRO_H
#define TRABALHO_JARDINEIRO_H

#include "../../Settings.h"
#include "../ferramenta/ferramenta.h"
#include <vector>
#include <iostream>

#include "jardim/jardim.h"

class Jardineiro {
    int linha;
    int coluna;
    bool dentroDoJardim;
    int movimentosFeitos;
    int entradasFeitas;
    int saidasFeitas;
    int plantacoesFeitas;
    int colheitasFeitas;

    Ferramenta* ferramentaMao;
    std::vector<Ferramenta*> ferramentas;

public:
    Jardineiro();
    ~Jardineiro();

    // Posição e estado
    bool estaNaPosicao(int l, int c) const;
    bool estaNoJardim() const;
    void entrarNoJardim(Jardim* j, int l, int c);
    void sairDoJardim();
    void colocarNoJardimInicial(Jardim* j, int l, int c);

    void mover(char direcao, int maxLinhas, int maxColunas);

    void resetarAcoesTurno();

    // Ferramentas
    void pegarFerramenta(Ferramenta* f);
    void largaFerramenta();
    void usaFerramenta(Solo& solo);
    void listarFerramentas() const;
    bool escolherFerramentaPorNumero(int numero);
    bool compraFerramenta(char tipo);
    Ferramenta* getFerramentaMao() const { return ferramentaMao; }

    //Plantações
    bool podePlantar() const;
    void registaPlantacao();
    bool podeColher() const;
    void registaColheita();


    int getLinha() const { return linha; }
    int getColuna() const { return coluna; }
};

#endif //TRABALHO_JARDINEIRO_H