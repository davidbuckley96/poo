//
// Created by GoodBarber on 02/11/2025.
//

#include "carroDeMao.h"
#include <iostream>
#include <cmath>

CarroDeMao::CarroDeMao()
    : Ferramenta('z')
{
    ativa = true; // nunca se desgasta
}

void CarroDeMao::usar(Solo& solo) {
    std::cout << "Use o carro de mão para mover uma planta viva para outra posição.\n";
    std::cout << "Este comando deve ser chamado com coordenadas específicas.\n";
    // Exemplo: moverPlanta(jardim, jardineiro, linhaOrigem, colOrigem, linhaDestino, colDestino);
}

void CarroDeMao::moverPlanta(Jardim& jardim, Jardineiro& jardineiro,
                             int origemL, int origemC, int destinoL, int destinoC) {
    if (!jardineiro.estaNoJardim()) {
        std::cout << "O jardineiro precisa estar dentro do jardim para usar o carro de mão.\n";
        return;
    }

    if (!jardim.coordenadaValida(origemL, origemC) ||
        !jardim.coordenadaValida(destinoL, destinoC)) {
        std::cout << "Coordenadas inválidas.\n";
        return;
    }

    Solo& origem = jardim.getSolo(origemL, origemC);
    Solo& destino = jardim.getSolo(destinoL, destinoC);

    Planta* planta = origem.getPlanta();
    if (!planta) {
        std::cout << "Não há nenhuma planta na posição de origem.\n";
        return;
    }

    if (destino.getPlanta() != nullptr) {
        std::cout << "A posição de destino já tem uma planta.\n";
        return;
    }

    // Calcula a distância (movimentos necessários)
    int distancia = std::abs(destinoL - origemL) + std::abs(destinoC - origemC);

    if (distancia > Settings::Jardineiro::max_movimentos) {
        std::cout << "O destino é muito longe! O jardineiro não consegue empurrar o carro de mão até lá.\n";
        return;
    }

    // Move a planta
    destino.setPlanta(planta);
    origem.setPlanta(nullptr);

    std::cout << "A planta foi movida de "
              << (char)('A' + origemL) << (char)('A' + origemC)
              << " para "
              << (char)('A' + destinoL) << (char)('A' + destinoC)
              << " com o carro de mão. (" << distancia << " movimentos usados)\n";
}

void CarroDeMao::mostrarInfo() const {
    std::cout << "Carro de Mão (Nº " << getNumeroSerie()
              << ") - Permite mover plantas dentro do jardim. [indestrutível]\n";
}
