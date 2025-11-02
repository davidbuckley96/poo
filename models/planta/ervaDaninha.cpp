//
// Created by GoodBarber on 01/11/2025.
//

#include "ervadaninha.h"
#include "../solo/solo.h"
#include "../jardim/jardim.h"

ErvaDaninha::ErvaDaninha()
    : Planta('e', "feia"),
      idade(0),
      instantesDesdeUltimaMultiplicacao(0)
{
    agua = Settings::ErvaDaninha::inicial_agua;
    nutrientes = Settings::ErvaDaninha::inicial_nutrientes;
}

void ErvaDaninha::atualiza(Jardim& jardim, int linha, int coluna) {
    if (!viva) return;
    idade++;
    instantesDesdeUltimaMultiplicacao++;

    Solo& solo = jardim.getSolo(linha, coluna);

    // Absorve 1 unidade de água (se houver)
    if (solo.getAgua() > 0) {
        solo.addAgua(-Settings::ErvaDaninha::absorcao_agua);
        agua += Settings::ErvaDaninha::absorcao_agua;
    }

    // Absorve 1 unidade de nutrientes (se houver)
    if (solo.getNutrientes() > 0) {
        solo.addNutrientes(-Settings::ErvaDaninha::absorcao_nutrientes);
        nutrientes += Settings::ErvaDaninha::absorcao_nutrientes;
    }

    // Morte natural após 60 instantes
    if (idade >= Settings::ErvaDaninha::morre_instantes) {
        morrer(solo);
        return;
    }

    // Multiplicação (após 5 instantes desde a última vez)
    if (nutrientes > Settings::ErvaDaninha::multiplica_nutrientes_maior &&
        instantesDesdeUltimaMultiplicacao >= Settings::ErvaDaninha::multiplica_instantes) {

        for (int dl = -1; dl <= 1; ++dl) {
            for (int dc = -1; dc <= 1; ++dc) {
                if (dl == 0 && dc == 0) continue;

                int nl = linha + dl;
                int nc = coluna + dc;

                if (jardim.coordenadaValida(nl, nc)) {
                    Solo& destino = jardim.getSolo(nl, nc);

                    // mata planta vizinha (se houver)
                    if (destino.getPlanta() != nullptr) {
                        destino.getPlanta()->morrer(destino);
                        destino.setPlanta(nullptr);
                    }

                    // nasce nova erva
                    ErvaDaninha* nova = new ErvaDaninha();
                    jardim.plantar(nl, nc, nova);
                    std::cout << "Uma erva daninha espalhou-se para uma posição vizinha!\n";

                    instantesDesdeUltimaMultiplicacao = 0;
                    return; // só cria uma nova por instante
                }
            }
        }
    }
}

void ErvaDaninha::morrer(Solo& solo) {
    if (!viva) return;
    viva = false;
    std::cout << "Uma erva daninha morreu após " << idade << " instantes.\n";
}