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
    std::cout << "Para usar o carro de mão, informe as coordenadas de origem e destino:\n";
    std::cout << "Use:  usar <lc_origem> <lc_destino>\n";
}

void CarroDeMao::mostrarInfo() const {
    std::cout << "Carro de Mão (Nº " << getNumeroSerie()
              << ") - Permite mover plantas dentro do jardim. [indestrutível]\n";
}
