//
// Created by GoodBarber on 22/10/2025.
//

#include "../jardim/jardim.h"
#include "../solo/solo.h"
#include "../planta/planta.h"
#include "../jardineiro/jardineiro.h"
#include <cstdlib>
#include <iostream>

#include "ferramenta/adubo.h"
#include "ferramenta/carroDeMao.h"
#include "ferramenta/regador.h"
#include "ferramenta/tesoura.h"


Jardim::Jardim(int l, int c, Jardineiro *j) : linhas(l), colunas(c), jardineiro(j) {
    if (l <= 0 || l > 26 || c <= 0 || c > 26) {
        throw std::invalid_argument("Tamanho invalido para jardim (maximo 26x26).");
    }

    grelha = new Solo*[linhas];
    for (int i=0; i < linhas; ++i) {
        grelha[i] = new Solo[colunas];
    }

    if (jardineiro != nullptr) {
        jardineiro->colocarNoJardimInicial(this, 0, 0);
    }

    for (int i = 0; i < 3; ++i)
        colocaFerramentaAleatoria();
}

Jardim::Jardim(int l, int c): linhas(l), colunas(c), jardineiro(nullptr), instanteAtual(0) {
    if (l <= 0 || l > 26 || c <= 0 || c > 26) {
        throw std::invalid_argument("Tamanho invalido para jardim (maximo 26x26).");

    }

    grelha = new Solo*[linhas];
    for (int i=0; i < linhas; ++i) {
        grelha[i] = new Solo[colunas];
    }

    for (int i = 0; i < 3; ++i)
        colocaFerramentaAleatoria();
}

Jardim::~Jardim() {
    for (int l = 0; l < linhas; ++l) {
        for (int c = 0; c < colunas; ++c) {
            delete grelha[l][c].getPlanta();
            delete grelha[l][c].getFerramenta();
        }
        delete[] grelha[l];
    }
    delete[] grelha;
}

Jardim::Jardim(const Jardim& outro)
    : linhas(outro.linhas),
      colunas(outro.colunas),
      grelha(nullptr),
      jardineiro(outro.jardineiro),
      instanteAtual(outro.instanteAtual)
{
    grelha = new Solo*[linhas];
    for (int l = 0; l < linhas; ++l)
        grelha[l] = new Solo[colunas];

    for (int l = 0; l < linhas; ++l) {
        for (int c = 0; c < colunas; ++c) {
            // copiar água e nutrientes
            grelha[l][c].addAgua(outro.grelha[l][c].getAgua() - grelha[l][c].getAgua());
            grelha[l][c].addNutrientes(outro.grelha[l][c].getNutrientes() - grelha[l][c].getNutrientes());


            if (outro.grelha[l][c].getPlanta())
                grelha[l][c].setPlanta(outro.grelha[l][c].getPlanta()->clone());
            else
                grelha[l][c].setPlanta(nullptr);


            if (outro.grelha[l][c].getFerramenta())
                grelha[l][c].setFerramenta(outro.grelha[l][c].getFerramenta()->clone());
            else
                grelha[l][c].setFerramenta(nullptr);

        }
    }
}

Jardim& Jardim::operator=(const Jardim& outro) {
    if (this == &outro) return *this;

    if (grelha) {
        for (int l = 0; l < linhas; ++l) {
            for (int c = 0; c < colunas; ++c) {
                delete grelha[l][c].getPlanta();
                delete grelha[l][c].getFerramenta();
                grelha[l][c].setPlanta(nullptr);
                grelha[l][c].setFerramenta(nullptr);
            }
            delete[] grelha[l];
        }
        delete[] grelha;
        grelha = nullptr;
    }

    linhas = outro.linhas;
    colunas = outro.colunas;
    jardineiro = outro.jardineiro;
    instanteAtual = outro.instanteAtual;

    grelha = new Solo*[linhas];
    for (int l = 0; l < linhas; ++l)
        grelha[l] = new Solo[colunas];

    for (int l = 0; l < linhas; ++l) {
        for (int c = 0; c < colunas; ++c) {
            // Copiar água/nutrientes
            grelha[l][c].addAgua(outro.grelha[l][c].getAgua() - grelha[l][c].getAgua());
            grelha[l][c].addNutrientes(outro.grelha[l][c].getNutrientes() - grelha[l][c].getNutrientes());

            if (outro.grelha[l][c].getPlanta())
                grelha[l][c].setPlanta(outro.grelha[l][c].getPlanta()->clone());
            else
                grelha[l][c].setPlanta(nullptr);

            if (outro.grelha[l][c].getFerramenta())
                grelha[l][c].setFerramenta(outro.grelha[l][c].getFerramenta()->clone());
            else
                grelha[l][c].setFerramenta(nullptr);
        }
    }

    return *this;
}

bool Jardim::coordenadaValida(int l, int c) const {
    return (l >= 0 && l < linhas && c >= 0 && c < colunas);
}

Solo& Jardim::getSolo(int l, int c) {
    if (!coordenadaValida(l, c)) {
        std::cout << "Coordenada inválida (" << l + 1 << "," << c + 1 << ")" << std::endl;
    }
    return grelha[l][c];
}

void Jardim::imprime() const {
    std::cout << "  ";
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
            std::cout << ch << " ";
        }
        std::cout << "\n";
    }
}

void Jardim::avancarInstante(int n) {
    for (int i = 0; i < n; ++i) {
        instanteAtual++;

        for (int l = 0; l < linhas; ++l) {
            for (int c = 0; c < colunas; ++c) {
                Planta* p = grelha[l][c].getPlanta();
                if (!p) continue;

                if (p->estaViva()) {
                    p->atualiza(*this, l, c);
                }

                if (!p-> estaViva()) {
                    delete p;
                    grelha[l][c].setPlanta(nullptr);
                }
            }
        }

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

void Jardim::apanhaFerramenta(Jardineiro &j) {
    if (!j.estaNoJardim()) return;

    int l = j.getLinha();
    int c = j.getColuna();

    Solo& s = getSolo(l, c);
    Ferramenta* f = s.getFerramenta();
    if (!f) return;

    j.pegarFerramenta(f);
    s.setFerramenta(nullptr);

    colocaFerramentaAleatoria();
}

void Jardim::colocaFerramentaAleatoria() {

    for (int tent = 0; tent < 1000; ++tent) {
        int l = rand() % linhas;
        int c = rand() % colunas;

        Solo& s = grelha[l][c];
        if (s.getFerramenta() == nullptr) {
            s.setFerramenta(criaFerramentaAleatoria());
            return;
        }
    }
}

Ferramenta* Jardim::criaFerramentaAleatoria() {
    int r = rand() % 4;
    switch (r) {
        case 0: return new Regador();
        case 1: return new Adubo();
        case 2: return new Tesoura();
        default: return new CarroDeMao();
    }
}

bool Jardim::moverPlanta(int lOrig, int cOrig, int lDest, int cDest) {
    if (!coordenadaValida(lOrig, cOrig) || !coordenadaValida(lDest, cDest)) {
        std::cout << "Coordenadas fora dos limites.\n";
        return false;
    }

    if (lOrig == lDest && cOrig == cDest) {
        std::cout << "Origem e destino são iguais.\n";
        return false;
    }

    // "espaço vazio" = sem planta, sem ferramenta e sem jardineiro em cima
    if (jardineiro && jardineiro->estaNaPosicao(lDest, cDest)) {
        std::cout << "Destino ocupado pelo jardineiro.\n";
        return false;
    }

    Solo& sOrig = getSolo(lOrig, cOrig);
    Solo& sDest = getSolo(lDest, cDest);

    Planta* p = sOrig.getPlanta();
    if (!p) {
        std::cout << "Não existe planta na origem.\n";
        return false;
    }

    if (!p->estaViva()) {
        std::cout << "A planta na origem não está viva.\n";
        return false;
    }

    if (sDest.getPlanta() != nullptr || sDest.getFerramenta() != nullptr) {
        std::cout << "Destino não está vazio.\n";
        return false;
    }

    // move o ponteiro da planta
    sOrig.setPlanta(nullptr);
    sDest.setPlanta(p);

    std::cout << "Planta movida de "
              << (char)('A' + lOrig) << (char)('A' + cOrig)
              << " para "
              << (char)('A' + lDest) << (char)('A' + cDest)
              << ".\n";

    return true;
}