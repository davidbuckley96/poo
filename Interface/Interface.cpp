//
// Created by diogo on 01/11/2025.
//

#include "Interface.h"
#include <sstream>

#include "../Comandos/Comandos.h"

using namespace std;

void Interface::inicializa() {
    stop = false;

    while (!stop) {
        verificaComando();
    }
}


void Interface::verificaComando() {

    cout << "Introduza o comando: ";
    getline(cin, comando);

    if (comando.empty()) { cout << "Linha vazia.\n"; return; }

    istringstream iss(comando);
    iss >> nomeComando;

    if (!comandos.existeJardim() && nomeComando != "jardim" && nomeComando != "executa") {
        cout << "Ainda não criaste o jardim. Usa 'jardim <lin> <col>' primeiro.\n";
        return;
    }


    if (nomeComando == "jardim") {
        if (!(iss >> linhas >> colunas)) {
            cout << "Uso: jardim <linhas> <colunas>\n";
            return;
        }

        comandos.criaJardim(linhas, colunas);

    } else if (nomeComando == "executa") {

        comandos.executa();

    } else if (nomeComando == "fim") {
        stop = true;
        comandos.fim();
    } else if (nomeComando == "avanca") {

        int n = 1;
        iss >> n;

        if (n <= 0) {
            cout << "Uso: avanca [n]  (n tem de ser positivo)\n";
            return;
        }

        comandos.avancaTempo(n);

    }else if (nomeComando == "lplantas") {

        if (!(iss >> linhaLetra >> colunaLetra)) {
            comandos.listaPlantas();
        }
        else {
            comandos.listaPlanta(linhaLetra, colunaLetra);
        }

    }else if (nomeComando == "larea") {
        comandos.listaPropriedades();

    }else if (nomeComando == "lsolo") {

        //valor default
        raio = 0;

        if (!(iss >> pos)) {
            cout << "Uso: lsolo <lc> [n]\n";
        }
        iss >> raio;

        if (pos.size() != 2) {
            cout << "Posição invalida (usa 2 letras, ex. df)\n";
            return;
        }

        linhaLetra = string(1, tolower(pos[0]));
        colunaLetra = string(1, tolower(pos[1]));


        comandos.verSolo(linhaLetra , colunaLetra, raio);

    }else if (nomeComando == "lferr") {
        comandos.listaFerramentas();
    }else if (nomeComando == "colhe") {

        if (!(iss >> pos)) {
            std::cout << "Uso: colhe <lc>\n";
            return;
        }

        // validar que tem 2 letras
        if (pos.size() != 2) {
            std::cout << "Posição inválida (usa 2 letras, ex.: df)\n";
            return;
        }

        linhaLetra = string(1, tolower(pos[0]));
        colunaLetra = string(1, tolower(pos[1]));


        comandos.colhe(linhaLetra, colunaLetra);
    }else if (nomeComando == "planta") {



    }else if (nomeComando == "larga") {

    }else if (nomeComando == "pega") {

    }else if (nomeComando == "compra") {

    }else if (nomeComando == "e" || nomeComando == "d" || nomeComando == "c" || nomeComando == "b") {

        comandos.desloca(nomeComando);

    }else if (nomeComando == "entra") {

    }else if (nomeComando == "sai") {

    }else if (nomeComando == "grava") {

    }else if (nomeComando == "recupera") {

    }else if (nomeComando == "apaga") {

    }
    else {
        cout << "Comando não existe, tente de novo\n";
    }




}


