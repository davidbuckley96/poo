//
// Created by GoodBarber on 01/11/2025.
//

#include "jardineiro.h"
#include "../solo/solo.h"
#include <iostream>

Jardineiro::Jardineiro()
    : linha(-1), coluna(-1), dentroDoJardim(false),
      movimentosFeitos(0), entradasSaidasFeitas(0),
      plantacoesFeitas(0), colheitasFeitas(0),
      ferramentaMao(nullptr) {}

bool Jardineiro::estaNaPosicao(int l, int c) const {
    return dentroDoJardim && l == linha && c == coluna;
}

bool Jardineiro::estaNoJardim() const {
    return dentroDoJardim;
}

void Jardineiro::entrarNoJardim(int l, int c) {
    if (entradasSaidasFeitas >= Settings::Jardineiro::max_entradas_saidas) {
        std::cout << "O jardineiro já entrou/saiu o máximo permitido neste turno.\n";
        return;
    }
    linha = l;
    coluna = c;
    dentroDoJardim = true;
    entradasSaidasFeitas++;
    std::cout << "Jardineiro entrou no jardim na posição "
              << (char)('A' + l) << (char)('A' + c) << ".\n";
}

void Jardineiro::sairDoJardim() {
    if (!dentroDoJardim) {
        std::cout << "O jardineiro já está fora do jardim.\n";
        return;
    }
    if (entradasSaidasFeitas >= Settings::Jardineiro::max_entradas_saidas) {
        std::cout << "O jardineiro não pode sair novamente neste turno.\n";
        return;
    }
    dentroDoJardim = false;
    linha = -1;
    coluna = -1;
    entradasSaidasFeitas++;
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
    movimentosFeitos++;

    std::cout << "Jardineiro moveu-se para "
              << (char)('A' + linha) << (char)('A' + coluna) << ".\n";
}

void Jardineiro::resetarAcoesTurno() {
    movimentosFeitos = 0;
    entradasSaidasFeitas = 0;
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
    std::cout << "Ferramentas transportadas:\n";
    for (auto* f : ferramentas)
        f->mostrarInfo();
    if (ferramentaMao) {
        std::cout << "Na mão: ";
        ferramentaMao->mostrarInfo();
    }
}

void Jardineiro::escolherFerramentaPorNumero(int numero) {
    for (auto it = ferramentas.begin(); it != ferramentas.end(); ++it) {
        if ((*it)->getNumeroSerie() == numero) {
            ferramentaMao = *it;
            ferramentas.erase(it);
            std::cout << "Ferramenta com Nº " << numero << " colocada na mão.\n";
            return;
        }
    }
    std::cout << "Ferramenta com Nº " << numero << " não encontrada.\n";
}
