//
// Created by diogo on 23/12/2025.
//

#ifndef TRABALHO_JOGO_H
#define TRABALHO_JOGO_H
#include <map>
#include "jardim/jardim.h"
#include "jardineiro/jardineiro.h"



class Jogo {
    int instante = 0;
    Jardineiro jardineiro;
    Jardim* jardim = nullptr;
    Jardim* backup = nullptr;
    std::map<std::string, Jardim*> backups;

    public:
    void avancar(int n);
    int getInstante() const;
    bool criaJardim(int l, int c);
    bool mover(char dir);
    bool existeJardim() const;
    void imprime() const;
    bool entra(char l, char c);
    bool sai();
    bool lFerr() const;
    bool larga();
    bool pega(int n);
    bool compra(char c);
    bool usar(char lChar, char cChar);
    bool usar(char lOrig, char cOrig, char lDest, char cDest);
    bool letraParaIndice(char lChar, char cChar, int &l, int &c) const;
    bool planta(char l, char c, char tipo);
    bool lplanta(char lChar, char cChar) const;
    bool lplantas() const;
    bool lsolo(char lChar, char cChar, int raio = 0) const;
    bool larea() const;
    bool colhe(char lChar, char cChar);
    bool grava(const std::string& nome);
    bool recupera(const std::string& nome);
    bool apaga(const std::string& nome);

    ~Jogo();
    Jogo();

};


#endif //TRABALHO_JOGO_H