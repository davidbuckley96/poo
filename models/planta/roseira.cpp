//
// Created by GoodBarber on 01/11/2025.
//

#include "roseira.h"
#include "../solo/solo.h"
#include "../jardim/jardim.h"

Roseira::Roseira()
    : Planta('r', "bonita")
{
    agua = Settings::Roseira::inicial_agua;
    nutrientes = Settings::Roseira::inicial_nutrientes;
}

void Roseira::atualiza(Jardim& jardim, int linha, int coluna) {
    if (!viva) return;
    Solo& solo = jardim.getSolo(linha, coluna);

    // Perdas por instante
    agua -= Settings::Roseira::perda_agua;
    nutrientes -= Settings::Roseira::perda_nutrientes;
    if (agua < 0) agua = 0;
    if (nutrientes < 0) nutrientes = 0;

    // Absorções do solo
    if (solo.getAgua() > 0) {
        int absorverAgua = std::min(Settings::Roseira::absorcao_agua, solo.getAgua());
        solo.addAgua(-absorverAgua);
        agua += absorverAgua;
    }
    if (solo.getNutrientes() > 0) {
        int absorverNutrientes = std::min(Settings::Roseira::absorcao_nutrientes, solo.getNutrientes());
        solo.addNutrientes(-absorverNutrientes);
        nutrientes += absorverNutrientes;
    }

    // Condições de morte
    if (agua <= Settings::Roseira::morre_agua_menor ||
        nutrientes <= Settings::Roseira::morre_nutrientes_menor ||
        nutrientes > Settings::Roseira::morre_nutrientes_maior) {
        morrer(solo);
        return;
    }

    // Verifica se está cercada (todas as posições vizinhas têm planta)
    bool cercada = true;
    for (int dl = -1; dl <= 1; ++dl) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dl == 0 && dc == 0) continue; // ignora a própria posição
            int nl = linha + dl;
            int nc = coluna + dc;
            if (jardim.coordenadaValida(nl, nc)) {
                Solo& vizinho = jardim.getSolo(nl, nc);
                if (vizinho.getPlanta() == nullptr) {
                    cercada = false;
                    break;
                }
            }
        }
        if (!cercada) break;
    }

    if (cercada) {
        morrer(solo);
        return;
    }

    // Multiplicação
    if (nutrientes > Settings::Roseira::multiplica_nutrientes_maior) {
        // Procura uma posição vizinha vazia
        for (int dl = -1; dl <= 1; ++dl) {
            for (int dc = -1; dc <= 1; ++dc) {
                if (dl == 0 && dc == 0) continue;
                int nl = linha + dl;
                int nc = coluna + dc;

                if (jardim.coordenadaValida(nl, nc)) {
                    Solo& destino = jardim.getSolo(nl, nc);
                    if (destino.getPlanta() == nullptr) {
                        Roseira* nova = new Roseira();
                        nova->addAgua(agua * Settings::Roseira::nova_agua_percentagem / 100);
                        nova->addNutrientes(Settings::Roseira::nova_nutrientes);

                        // Atualiza a original
                        nutrientes = Settings::Roseira::original_nutrientes;
                        agua = agua * Settings::Roseira::original_agua_percentagem / 100;

                        jardim.plantar(nl, nc, nova);
                        std::cout << "Uma roseira multiplicou-se para uma posição vizinha!\n";
                        return; // só cria uma por instante
                    }
                }
            }
        }
    }
}

void Roseira::morrer(Solo& solo) {
    if (!viva) return;
    viva = false;

    // Devolve metade dos nutrientes e metade da água ao solo
    solo.addAgua(agua / 2);
    solo.addNutrientes(nutrientes / 2);
    agua = 0;
    nutrientes = 0;

    std::cout << "Uma roseira morreu, devolvendo metade da água e nutrientes ao solo.\n";
}
