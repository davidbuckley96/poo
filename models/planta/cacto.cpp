//
// Created by GoodBarber on 01/11/2025.
//

#include "cacto.h"
#include "../solo/solo.h"
#include "../jardim/jardim.h"

Cacto::Cacto()
    : Planta('c', "neutra"),
      instantesAguaAlta(0),
      instantesNutrientesZero(0) {}

void Cacto::atualiza(Jardim& jardim, int linha, int coluna) {
    if (!viva) return;

    Solo& solo = jardim.getSolo(linha, coluna);

    // Absorção de água 25%
    int absorvida = solo.getAgua() * Settings::Cacto::absorcao_agua_percentagem / 100;
    solo.addAgua(-absorvida);
    agua += absorvida;

    // Absorção de nutrientes (até 5 unidades)
    int nutrientesDisponiveis = solo.getNutrientes();
    int absorver = std::min(Settings::Cacto::absorcao_nutrientes, nutrientesDisponiveis);
    solo.addNutrientes(-absorver);
    nutrientes += absorver;

    // Monitorar condições de morte
    if (solo.getAgua() > Settings::Cacto::morre_agua_solo_maior)
        instantesAguaAlta++;
    else
        instantesAguaAlta = 0;

    if (solo.getNutrientes() <= 0)
        instantesNutrientesZero++;
    else
        instantesNutrientesZero = 0;

    // Condições de morte
    if (instantesAguaAlta >= Settings::Cacto::morre_agua_solo_instantes ||
        instantesNutrientesZero > Settings::Cacto::morre_nutrientes_solo_instantes) {
        morrer(solo);
        return;
    }

    // Multiplicação
    if (nutrientes > Settings::Cacto::multiplica_nutrientes_maior &&
        agua > Settings::Cacto::multiplica_agua_maior) {

        // Procurar uma posição vazia (TESTE simplificado: tenta apenas abaixo ou à direita)
        int novaLinha = linha + 1;
        int novaColuna = coluna;

        if (novaLinha < 26 && jardim.coordenadaValida(novaLinha, novaColuna)) {
            Solo& destino = jardim.getSolo(novaLinha, novaColuna);
            if (destino.getPlanta() == nullptr) {
                Cacto* novo = new Cacto();

                // divide os recursos
                novo->addAgua(agua / 2);
                novo->addNutrientes(nutrientes / 2);
                agua /= 2;
                nutrientes /= 2;

                jardim.plantar(novaLinha, novaColuna, novo);
                std::cout << "Um cacto multiplicou-se para uma posição vizinha!\n";
            }
        }
    }
}

void Cacto::morrer(Solo& solo) {
    if (!viva) return;
    viva = false;

    // Devolve nutrientes, mas não a água
    solo.addNutrientes(nutrientes);
    nutrientes = 0;
    agua = 0;

    std::cout << "Um cacto morreu, devolvendo apenas nutrientes ao solo.\n";
}
