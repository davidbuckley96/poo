//
// Created by diogo on 01/11/2025.
//

#ifndef TRABALHO_COMANDOS_H
#define TRABALHO_COMANDOS_H


#include "../jardim.h"

using namespace std;

class Comandos {
    private:
    Jardim* jardim;
    bool jardimCriado;
    int l ;
    int c ;


    public:
    void criaJardim(int linhas, int colunas);
    int getLinhas() const {return l;};
    int getColunas() const {return c;};
    Comandos();
    ~Comandos();
    bool existeJardim() const;
    void avancaTempo(int n);
    void listaPlantas();
    void listaPlanta(const string& linhas, const string& colunas);
    void listaPropriedades();
    void verSolo(string& linha, string& coluna, int raio);
    void listaFerramentas();
    void colhe(string& linha, string& coluna);
    void planta();
    void larga();
    void pega();
    void compra();
    void desloca(string direção);
    void entra();
    void sai();
    void grava();
    void recupera();
    void apaga();
    void executa();
    void fim();


};


#endif //TRABALHO_COMANDOS_H