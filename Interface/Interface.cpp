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

        cout << "Executar comandos a partir de ficheiro (por implementar).\n";

    } else if (nomeComando == "fim") {
        stop = true;
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

    }



}


