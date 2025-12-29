//
// Created by GoodBarber on 01/11/2025.
//

#include "jardineiro.h"
#include "../solo/solo.h"
#include <iostream>

#include "ferramenta/adubo.h"
#include "ferramenta/carroDeMao.h"
#include "ferramenta/regador.h"
#include "ferramenta/tesoura.h"



Jardineiro::~Jardineiro() {
    delete ferramentaMao;
    ferramentaMao = nullptr;

    for (Ferramenta* f : ferramentas) {
        delete f;
    }
    ferramentas.clear();
}


Jardineiro::Jardineiro()
    : linha(-1), coluna(-1), dentroDoJardim(false),
      movimentosFeitos(0), entradasFeitas(0), saidasFeitas(0),
      plantacoesFeitas(0), colheitasFeitas(0),
      ferramentaMao(nullptr) {}

bool Jardineiro::estaNaPosicao(int l, int c) const {
    return dentroDoJardim && l == linha && c == coluna;
}

bool Jardineiro::estaNoJardim() const {
    return dentroDoJardim;
}

void Jardineiro::entrarNoJardim(Jardim* j, int l, int c) {
    if (entradasFeitas >= Settings::Jardineiro::max_entradas_saidas) {
        std::cout << "O jardineiro já entrou o máximo permitido neste turno.\n";
        return;
    }

    dentroDoJardim = true;
    entradasFeitas++;

    linha = l;
    coluna = c;
}

void Jardineiro::sairDoJardim() {
    if (!dentroDoJardim) {
        std::cout << "O jardineiro já está fora do jardim.\n";
        return;
    }
    if (saidasFeitas >= Settings::Jardineiro::max_entradas_saidas) {
        std::cout << "O jardineiro não pode sair novamente neste turno.\n";
        return;
    }
    dentroDoJardim = false;
    linha = -1;
    coluna = -1;
    saidasFeitas++;
    std::cout << "Jardineiro saiu do jardim.\n";
}

void Jardineiro::mover(char direcao, int maxLinhas, int maxColunas) {
    if (!dentroDoJardim) {
        std::cout << "O jardineiro precisa estar dentro do jardim para se mover.\n";
        return;
    }

    if (movimentosFeitos >= Settings::Jardineiro::max_movimentos) {
        std::cout << "Limite de movimentos por turno atingido.\n";
        return;
    }

    movimentosFeitos++;

    int novaL = linha;
    int novaC = coluna;

    switch (direcao) {
        case 'c': novaL--; break; // cima
        case 'b': novaL++; break; // baixo
        case 'e': novaC--; break; // esquerda
        case 'd': novaC++; break; // direita
        default:
            std::cout << "Direção inválida! Use 'c', 'b', 'e' ou 'd'.\n";
            return;
    }

    if (novaL < 0 || novaL >= maxLinhas || novaC < 0 || novaC >= maxColunas) {
        std::cout << "Movimento inválido: fora dos limites do jardim.\n";
        return;
    }

    linha = novaL;
    coluna = novaC;


    std::cout << "Jardineiro moveu-se para "
              << (char)('A' + linha) << (char)('A' + coluna) << ".\n";
}

void Jardineiro::resetarAcoesTurno() {
    movimentosFeitos = 0;
    entradasFeitas = 0;
    saidasFeitas = 0;
    plantacoesFeitas = 0;
    colheitasFeitas = 0;
}

void Jardineiro::pegarFerramenta(Ferramenta* f) {
    if (!f) return;
    ferramentas.push_back(f);
    std::cout << "Jardineiro apanhou a ferramenta " << f->getCharRepr()
              << " (Nº " << f->getNumeroSerie() << ").\n";
}

void Jardineiro::largaFerramenta() {
    if (!ferramentaMao) {
        std::cout << "Nenhuma ferramenta na mão para largar.\n";
        return;
    }
    ferramentas.push_back(ferramentaMao);
    std::cout << "Ferramenta " << ferramentaMao->getCharRepr()
              << " (Nº " << ferramentaMao->getNumeroSerie()
              << ") foi largada.\n";
    ferramentaMao = nullptr;
}

void Jardineiro::usaFerramenta(Solo& solo) {
    if (!ferramentaMao) {
        std::cout << "O jardineiro não tem nenhuma ferramenta na mão.\n";
        return;
    }
    if (!ferramentaMao->estaAtiva()) {
        std::cout << "A ferramenta está inativa.\n";
        return;
    }
    ferramentaMao->usar(solo);
}

void Jardineiro::listarFerramentas() const {

    if (ferramentas.empty()) {
        std::cout << "Nao tem ferramentas no inventario.\n";
    } else {
        std::cout << "Ferramentas no inventario:\n";
        for (auto f : ferramentas) {
            std::cout << " - ";
            f->mostrarInfo();
        }
    }

    if (ferramentaMao) {
        std::cout << "Na mao (ativa):\n";
        ferramentaMao->mostrarInfo();
    } else {
        std::cout << "Na mao: nenhuma\n";
    }
}

bool Jardineiro::escolherFerramentaPorNumero(int numero) {

    if (ferramentaMao) {
        ferramentas.push_back(ferramentaMao);
        ferramentaMao = nullptr;

        std::cout << "Guardou a ferramenta que tinha na mão.\n";
    }

    for (auto it = ferramentas.begin(); it != ferramentas.end(); ++it) {
        if ((*it)->getNumeroSerie() == numero) {
            ferramentaMao = *it;
            ferramentas.erase(it);

            std::cout << "Ferramenta com Nº " << numero << " colocada na mão.\n";
            return true;
        }
    }

    std::cout << "Ferramenta com Nº " << numero << " não encontrada.\n";
    return false;
}

void Jardineiro::colocarNoJardimInicial(Jardim* j, int l, int c) {
    dentroDoJardim = true;
    linha = l;
    coluna = c;
}


bool Jardineiro::compraFerramenta(char tipo) {
    tipo = std::tolower(tipo);

    Ferramenta* f = nullptr;

    switch (tipo) {
        case 'g': f = new Regador(); break;
        case 'a': f = new Adubo(); break;
        case 't': f = new Tesoura(); break;
        case 'z': f = new CarroDeMao(); break;
        default:
            std::cout << "Tipo de ferramenta invalido. Use g, a, t, z.\n";
            return false;
    }

    pegarFerramenta(f);
    return true;

}

bool Jardineiro::podePlantar() const {
    return plantacoesFeitas < 2;
}

void Jardineiro::registaPlantacao() {
    ++plantacoesFeitas;
}

bool Jardineiro::podeColher() const {
    return colheitasFeitas < 5;
}

void Jardineiro::registaColheita() {
    ++colheitasFeitas;
}
