//
// Created by GoodBarber on 02/11/2025.
//

#include "plantaExotica.h"
#include "../solo/solo.h"
#include "../jardim/jardim.h"
#include "../planta/ervadaninha.h"

PlantaExotica::PlantaExotica()
    : Planta('x', "neutra"), idade(0)
{
    agua = 10;
    nutrientes = 5;
}

void PlantaExotica::atualiza(Jardim& jardim, int linha, int coluna) {
    if (!viva) return;
    idade++;

    Solo& solo = jardim.getSolo(linha, coluna);

    // Absorve 1 água e 1 nutriente do solo (se houver)
    if (solo.getAgua() > 0) {
        solo.addAgua(-1);
        agua += 1;
    }
    if (solo.getNutrientes() > 0) {
        solo.addNutrientes(-1);
        nutrientes += 1;
    }

    // Verifica morte por idade ou excesso de água
    if (idade > 3 || agua > 40) {
        morrer(solo);
        return;
    }

    // Multiplicação: se água < 30
    if (agua < 30) {
        int novasCriadas = 0;

        for (int dl = -1; dl <= 1 && novasCriadas < 2; ++dl) {
            for (int dc = -1; dc <= 1 && novasCriadas < 2; ++dc) {
                if (dl == 0 && dc == 0) continue; // ignora a própria posição

                int nl = linha + dl;
                int nc = coluna + dc;

                if (!jardim.coordenadaValida(nl, nc))
                    continue;

                Solo& destino = jardim.getSolo(nl, nc);

                // verifica se há planta vizinha e se não é ErvaDaninha
                Planta* existente = destino.getPlanta();
                if (existente != nullptr) {
                    if (typeid(*existente) == typeid(ErvaDaninha))
                        continue; // não invade erva daninha
                    else
                        continue; // também não sobrepõe outras plantas
                }

                // cria nova planta exótica
                PlantaExotica* nova = new PlantaExotica();
                jardim.plantar(nl, nc, nova);
                novasCriadas++;

                std::cout << "Uma planta exótica espalhou-se para uma posição vizinha!\n";
            }
        }
    }
}

void PlantaExotica::morrer(Solo& solo) {
    if (!viva) return;
    viva = false;

    // devolve uma parte da água e nutrientes ao solo
    solo.addAgua(agua / 3);
    solo.addNutrientes(nutrientes / 3);

    agua = 0;
    nutrientes = 0;

    std::cout << "Uma planta exótica morreu após " << idade << " instantes.\n";
}
