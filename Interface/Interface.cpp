//
// Created by diogo on 01/11/2025.
//

#include "Interface.h"
#include "Comandos/CmdAvanca.h"

#include <iostream>
#include <sstream>

#include "CmdColhe.h"
#include "CmdCompra.h"
#include "CmdEntra.h"
#include "CmdFim.h"
#include "CmdJardim.h"
#include "CmdLArea.h"
#include "CmdLarga.h"
#include "CmdLFerr.h"
#include "CmdLPlanta.h"
#include "CmdLPlantas.h"
#include "CmdLSolo.h"
#include "CmdMove.h"
#include "CmdPega.h"
#include "CmdPlanta.h"
#include "CmdSai.h"


#include <fstream>
#include <iostream>

#include "CmdApaga.h"
#include "CmdExecuta.h"
#include "CmdGrava.h"
#include "CmdRecupera.h"
#include "CmdUsar.h"


bool Interface::executaFicheiro(const string& nomeFicheiro) {
    ifstream f(nomeFicheiro);
    if (!f) {
        std::cout << "Nao foi possivel abrir ficheiro.\n";
        return true;
    }

    string linha;
    while (getline(f, linha)) {
        if (linha.empty()) continue;

        bool continua = processaLinha(linha);
        if (!continua) return false;
    }
    return true;
}

void Interface::run() {
    string linha;

    while (true) {
        cout << "Insira um comando valido: " << endl;
        cout << "> ";
        
        if (!getline(cin, linha)) 
            break;
        
        if (!processaLinha(linha))
            break;
    }
}

bool Interface::processaLinha(const string &linha) {
    stringstream ss(linha);

    string comando;
    ss >> comando;

    if (comando.empty())
        return true;

    if (comando == "fim") {
        return false;
    }

    if (comando == "executa") {
        string ficheiro;

        if (!(ss >> ficheiro)) {
            cout << "O comando 'executa' requer um nome de ficheiro.\n";
            return true;
        }

        string extra;
        if (ss >> extra) {
            cout << "O comando 'executa' recebe apenas um ficheiro.\n";
            return true;
        }

        return executaFicheiro(ficheiro);
    }


    Comando* c = criarComando(comando, ss);

    if (!c) {
        return true;
    }

    if (!jogo.existeJardim() &&
       comando != "jardim" ) {
        cout << "Ainda nao existe jardim.\n";
        delete c;
        return true;
       }

    c->executar(jogo);
    delete c;

    return true;
}

Comando* Interface::criarComando(const string &comando, stringstream &ss) {

    if (comando == "avanca") {
            int n;

            //Caso não haja um numero usa o default
            if (!(ss >> n ))
                return new CmdAvanca();

            //Caso haja mais que um numero
            string extra;
            if (ss >> extra) {
                cout << "Avanca recebe apenas um numero\n";
                return nullptr;
            }

            //numero valido
            return new CmdAvanca(n);
    }

    if (comando == "e" || comando == "d" || comando == "c" || comando == "b") {
        return new CmdMove(comando[0]);
    }

    if (comando == "jardim") {
        int l, c;

        if (!(ss >> l >> c)) {
            std::cout << "Jardim recebe dois numeros: jardim <linhas> <colunas>\n";
            return nullptr;
        }

        std::string extra;
        if (ss >> extra) {
            std::cout << "Jardim recebe apenas dois numeros\n";
            return nullptr;
        }

        return new CmdJardim(l, c);

    }

    if (comando == "sai") {
        std::string extra;
        if (ss >> extra) {
            std::cout << "Sai nao recebe argumentos\n";
            return nullptr;
        }
        return new CmdSai();
    }

    if (comando == "entra") {
        char l, c;
        if (!(ss >> l >> c)) {
            std::cout << "Entra recebe dois numeros: entra <linha> <coluna>\n";
            return nullptr;
        }
        std::string extra;
        if (ss >> extra) {
            std::cout << "Entra recebe apenas dois numeros\n";
            return nullptr;
        }
        return new CmdEntra(l, c);
    }


    if (comando == "compra") {
        char t;

        if (!(ss >> t)) {
            cout << "Insira (g, a, t, z)\n";
            return nullptr;
        }

        string extra;
        if (ss >> extra) {
            cout << "Insira apenas um caracter (g, a, t, z)\n";
            return nullptr;
        }

        return new CmdCompra(t);
    }

    if (comando == "larga") {
        string extra;
        if (ss >> extra) {
            cout << "O comando 'larga' nao recebe parametros.\n";
            return nullptr;
        }
        return new CmdLarga();
    }

    if (comando == "pega") {
        int n;

        if (!(ss >> n)) {
            cout << "O comando 'pega' requer um numero de serie.\n";
            return nullptr;
        }

        string extra;
        if (ss >> extra) {
            cout << "O comando 'pega' recebe apenas um numero.\n";
            return nullptr;
        }

        if (n <= 0) {
            cout << "Numero de serie invalido.\n";
            return nullptr;
        }

        return new CmdPega(n);
    }

    if (comando == "lferr") {
        string extra;
        if (ss >> extra) {
            cout << "O comando 'lferr' nao recebe parametros.\n";
            return nullptr;
        }
        return new CmdLFerr();
    }

    if (comando == "usar") {
        std::string pos;
        if (!(ss >> pos) || pos.size() != 2) {
            std::cout << "Use: usar <lc>\n";
            return nullptr;
        }
        return new CmdUsar(pos[0], pos[1]);
    }

    if (comando == "planta") {
        std::string pos;
        char tipo;

        if (!(ss >> pos >> tipo)) {
            std::cout << "Use: planta <lc> <tipo>\n";
            return nullptr;
        }

        if (pos.size() != 2) {
            std::cout << "Use: planta <lc> <tipo>\n";
            return nullptr;
        }

        std::string extra;
        if (ss >> extra) {
            std::cout << "Use: planta <lc> <tipo>\n";
            return nullptr;
        }

        tipo = std::tolower(tipo);
        if (tipo!='c' && tipo!='r' && tipo!='e' && tipo!='x') {
            std::cout << "Tipo invalido. Use c/r/e/x\n";
            return nullptr;
        }

        return new CmdPlanta(pos[0], pos[1], tipo);
    }


    if (comando == "lplanta") {
        string pos;

        if (!(ss >> pos)) {
            cout << "Use: lplanta <lc>\n";
            return nullptr;
        }

        if (pos.size() != 2) {
            cout << "A posicao deve ter 2 letras (ex: fb).\n";
            return nullptr;
        }

        string extra;
        if (ss >> extra) {
            cout << "Use apenas: lplanta <lc>\n";
            return nullptr;
        }

        return new CmdLPlanta(pos[0], pos[1]);
    }

    if (comando == "lplantas") {
        string extra;

        if (ss >> extra) {
            cout << "O comando 'lplantas' nao recebe parametros.\n";
            return nullptr;
        }
        return new CmdLPlantas();
    }

    if (comando == "lsolo") {

        string pos;
        if (!(ss >> pos)) {
            cout << "Use: lsolo <lc> [raio]\n";
            return nullptr;
        }

        if (pos.size() != 2) {
            cout << "A posicao deve ter 2 letras (ex: fb).\n";
            return nullptr;
        }

        int raio = 0;
        ss >> raio;

        std::string extra;
        if (ss >> extra) {
            cout << "Use apenas: lsolo <lc> [raio]\n";
            return nullptr;
        }

        return new CmdLSolo(pos[0], pos[1], raio);
    }

    if (comando == "larea") {
        std::string extra;
        if (ss >> extra) {
            cout << "O comando 'larea' nao recebe parametros.\n";
            return nullptr;
        }
        return new CmdLArea();
    }

    if (comando == "colhe") {
        string pos;

        if (!(ss >> pos) || pos.size() != 2) {
            cout << "Use: colhe <lc>\n";
            return nullptr;
        }

        std::string extra;
        if (ss >> extra) {
            cout << "Use apenas: colhe <lc>\n";
            return nullptr;
        }

        return new CmdColhe(pos[0], pos[1]);
    }

    if (comando == "grava") {
        string nome;

        if (!(ss >> nome)) {
            cout << "O comando 'grava' requer um nome.\n";
            return nullptr;
        }

        string extra;
        if (ss >> extra) {
            cout << "O comando 'grava' recebe apenas um nome.\n";
            return nullptr;
        }

        return new CmdGrava(nome);
    }

    if (comando == "recupera") {
        string nome;

        if (!(ss >> nome)) {
            cout << "O comando 'recupera' requer um nome.\n";
            return nullptr;
        }

        string extra;
        if (ss >> extra) {
            cout << "O comando 'recupera' recebe apenas um nome.\n";
            return nullptr;
        }

        return new CmdRecupera(nome);
    }

    if (comando == "apaga") {
        string nome;

        if (!(ss >> nome)) {
            cout << "O comando 'apaga' requer um nome.\n";
            return nullptr;
        }

        string extra;
        if (ss >> extra) {
            cout << "O comando 'apaga' recebe apenas um nome.\n";
            return nullptr;
        }

        return new CmdApaga(nome);
    }

    std::cout << "Erro: comando desconhecido\n";
    return nullptr;

}
