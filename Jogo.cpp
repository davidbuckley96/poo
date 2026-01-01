//
// Created by diogo on 23/12/2025.
//

#include "Jogo.h"

#include "planta/cacto.h"
#include "planta/ervadaninha.h"
#include "planta/plantaExotica.h"
#include "planta/roseira.h"
#include <fstream>

Jogo::Jogo() : jardim(nullptr), instante(0) {
}

Jogo::~Jogo() {
    delete jardim;
    for (auto &p : backups)
        delete p.second;
}

bool Jogo::letraParaIndice(char lChar, char cChar, int &l, int &c) const {

    lChar = std::tolower(lChar);
    cChar = std::tolower(cChar);

    if (lChar < 'a' || lChar > 'z' ||
        cChar < 'a' || cChar > 'z')
        return false;

    l = lChar - 'a';
    c = cChar - 'a';

    return true;
}

void Jogo::avancar(int n) {
    if (n <= 0) n = 1;

    if (!jardim) {
        std::cout << "Nao existe jardim.\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        instante++;
        jardim->avancarInstante(1);
        jardineiro.resetarAcoesTurno();
    }

    //instante += n;

    //jardineiro.resetarAcoesTurno();
    //jardim->imprime();
}

int Jogo::getInstante() const {
    if (jardim == nullptr) return 0;
    return instante;
}

bool Jogo::mover(char dir) {

    if (jardim == nullptr) {
        std::cout << "Ainda não existe jardim.\n";
        return false;
    }

    if (!jardineiro.estaNoJardim()) {
        std::cout << "O jardineiro ainda não entrou no jardim.\n";
        return false;
    }

    jardineiro.mover(dir, jardim -> getLinhas(), jardim -> getColunas());
    jardim->apanhaFerramenta(jardineiro);
    jardim->imprime();

    return true;
}

bool Jogo::criaJardim(int l, int c) {

    if (jardim != nullptr) {
        std::cout << "Jardim ja foi criado.\n";
        return false;
    }

    try {
        jardim = new Jardim(l, c, &jardineiro);
        return true;
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
        return false;
    }

}

bool Jogo::existeJardim() const {
    return jardim != nullptr;
}

void Jogo::imprime() const {
    if (jardim == nullptr) {
        std::cout << "Ainda nao existe jardim.\n";
        return;
    }

    jardim -> imprime();
}

bool Jogo::entra(char lChar, char cChar) {
    if (jardim == nullptr) {
        std::cout << "Ainda nao existe jardim.\n";
        return false;
    }

    int l, c;

    if (!letraParaIndice(lChar, cChar, l, c)) {
        std::cout << "Coordenadas invalidas.\n";
        return false;
    }

    if (l < 0 || l >= jardim->getLinhas() || c < 0 || c >= jardim->getColunas()) {
        std::cout << "Entrada invalida: fora dos limites do jardim.\n";
        return false;
    }

    jardineiro.entrarNoJardim(jardim, l, c);
    jardim->apanhaFerramenta(jardineiro);
    jardim->imprime();
    return true;
}

bool Jogo::sai() {
    if (jardim == nullptr) {
        std::cout << "Ainda nao existe jardim.\n";
        return false;
    }

    jardineiro.sairDoJardim();
    jardim->imprime();

    return true;
}

bool Jogo::compra(char c) {

    if (jardim == nullptr) {
        std::cout << "Ainda nao existe jardim.\n";
        return false;
    }

    if (!jardineiro.compraFerramenta(c))
        return false;

    return true;

}

bool Jogo::larga() {
    if (!jardim) {
        std::cout << "Ainda nao existe jardim.\n";
        return false;
    }

    jardineiro.largaFerramenta();
    return true;
}

bool Jogo::lFerr() const {
    if (!jardim) {
        std::cout << "Ainda nao existe jardim.\n";
        return false;
    }

    if (!jardineiro.estaNoJardim()){
        std::cout << "Nenhum jardineiro dentro do jardim.\n";
        return false;
    }

    jardineiro.listarFerramentas();
    return true;
}

bool Jogo::pega(int n) {
    if (!jardim) {
        std::cout << "Ainda nao existe jardim.\n";
        return false;
    }

    jardineiro.escolherFerramentaPorNumero(n);
    return true;
}

bool Jogo::usar(char lChar, char cChar) {
    if (!jardim) {
        std::cout << "Ainda nao existe jardim.\n";
        return false;
    }
    if (!jardineiro.estaNoJardim()) {
        std::cout << "O jardineiro nao esta dentro do jardim.\n";
        return false;
    }

    int l, c;
    if (!letraParaIndice(lChar, cChar, l, c)) {
        std::cout << "Coordenadas invalidas.\n";
        return false;
    }

    if (!jardim->coordenadaValida(l, c)) {
        std::cout << "Posicoes fora dos limites.\n";
        return false;
    }

    Solo& solo = jardim->getSolo(l, c);
    jardineiro.usaFerramenta(solo);
    return true;
}

bool Jogo::planta(char lChar, char cChar, char tipo) {

    if (!jardim) {
        std::cout << "Ainda nao existe jardim.\n";
        return true;
    }

    int l, c;

    if (!letraParaIndice(lChar, cChar, l, c)) {
        std::cout << "Coordenadas invalidas.\n";
        return true;
    }

    if (l < 0 || l >= jardim->getLinhas() || c < 0 || c >= jardim->getColunas()) {
        std::cout << "Posicao fora dos limites.\n";
        return true;
    }

    if (!jardineiro.podePlantar()) {
        std::cout << "Ja plantou o maximo neste turno.\n";
        return true;
    }

    Solo& s = jardim->getSolo(l, c);
    if (s.getPlanta() != nullptr) {
        std::cout << "Ja existe uma planta nessa posicao.\n";
        return true;
    }

    Planta* p = nullptr;
    tipo = std::toupper(tipo);

    switch (tipo) {
        case 'C': p = new Cacto(); break;
        case 'R': p = new Roseira(); break;
        case 'E': p = new ErvaDaninha(); break;
        case 'X': p = new PlantaExotica(); break;
        default:
            std::cout << "Tipo invalido. Use C, R, E, X.\n";
            return true;
    }

    s.setPlanta(p);
    jardineiro.registaPlantacao();

    jardim->imprime();
    return true;

}

bool Jogo::lplanta(char lChar, char cChar) const {

    if (!jardim) {
        std::cout << "Ainda nao existe jardim.\n";
        return true;
    }

    int l, c;
    if (!letraParaIndice(lChar, cChar, l, c)) {
        std::cout << "Coordenadas invalidas.\n";
        return true;
    }

    if (l < 0 || l >= jardim->getLinhas() || c < 0 || c >= jardim->getColunas()) {
        std::cout << "Posicao fora dos limites.\n";
        return true;
    }

    Solo& s = jardim->getSolo(l, c);
    Planta* p = s.getPlanta();

    if (!p) {
        std::cout << "Nao existe planta nessa posicao.\n";
        return true;
    }

    p->mostrarInfo();

    return true;
}

bool Jogo::lplantas() const {

    if (!jardim) {
        std::cout << "Ainda nao existe jardim.\n";
        return true;
    }

    bool encontrou = false;

    for (int l = 0; l < jardim->getLinhas(); ++l) {
        for (int c = 0; c < jardim->getColunas(); ++c) {
            const Solo& s = jardim->getSolo(l, c);
            Planta* p = s.getPlanta();

            if (!p) continue;

            encontrou = true;

            char lChar = static_cast<char>('a' + l);
            char cChar = static_cast<char>('a' + c);

            std::cout << "Planta em " << lChar << cChar << ":\n";

            p->mostrarInfo();

            std::cout << "Solo: agua=" << s.getAgua()
                      << ", nutrientes=" << s.getNutrientes() << "\n";

            std::cout << "----\n";
        }
    }

    if (!encontrou) {
        std::cout << "Nao existem plantas no jardim.\n";
    }

    return true;
}

bool Jogo::lsolo(char lChar, char cChar, int raio) const {

    if (!jardim) {
        std::cout << "Ainda nao existe jardim.\n";
        return true;
    }

    int l0, c0;

    if (!letraParaIndice(lChar, cChar, l0, c0)) {
        std::cout << "Coordenadas invalidas.\n";
        return true;
    }

    if (l0 < 0 || l0 >= jardim->getLinhas() || c0 < 0 || c0 >= jardim->getColunas()) {
        std::cout << "Posicao fora dos limites.\n";
        return true;
    }

    if (raio < 0) raio = 0;

    int lMin = std::max(0, l0 - raio);
    int lMax = std::min(jardim->getLinhas() - 1, l0 + raio);
    int cMin = std::max(0, c0 - raio);
    int cMax = std::min(jardim->getColunas() - 1, c0 + raio);

    for (int l = lMin; l <= lMax; ++l) {
        for (int c = cMin; c <= cMax; ++c) {
            const Solo& s = jardim->getSolo(l, c);

            char lCharOut = ('a' + l);
            char cCharOut = ('a' + c);

            std::cout << "Solo " << lCharOut << cCharOut << ":\n";

            std::cout << "  agua=" << s.getAgua()
                      << " nutrientes=" << s.getNutrientes() << "\n";

            if (s.getPlanta())
                std::cout << "  planta=" << s.getPlanta()->getCharRepr() << "\n";
            else
                std::cout << "  planta=nenhuma\n";

            if (s.getFerramenta())
                std::cout << "  ferramenta=" << s.getFerramenta()->getCharRepr() << "\n";
            else
                std::cout << "  ferramenta=nenhuma\n";

            std::cout << "----\n";
        }
    }

    return true;
}

bool Jogo::larea() const {

    if (!jardim) {
        std::cout << "Ainda nao existe jardim.\n";
        return true;
    }

    bool encontrou = false;

    for (int l = 0; l < jardim->getLinhas(); ++l) {
        for (int c = 0; c < jardim->getColunas(); ++c) {
            const Solo s = jardim->getSolo(l, c);

            bool vazioTotal =
                (s.getPlanta() == nullptr) &&
                (s.getFerramenta() == nullptr) &&
                (s.getAgua() == 0) &&
                (s.getNutrientes() == 0);

            if (vazioTotal) continue;

            encontrou = true;

            char lChar = ('a' + l);
            char cChar = ('a' + c);

            std::cout << "Posicao " << lChar << cChar << ":\n";


            std::cout << "  Solo: agua=" << s.getAgua()
                      << " nutrientes=" << s.getNutrientes() << "\n";


            if (s.getPlanta()) {
                std::cout << "  Planta: ";
                s.getPlanta()->mostrarInfo();
            } else {
                std::cout << "  Planta: nenhuma\n";
            }

            if (s.getFerramenta()) {
                std::cout << "  Ferramenta: " << s.getFerramenta()->getCharRepr()
                          << " (Nº " << s.getFerramenta()->getNumeroSerie() << ")\n";
            } else {
                std::cout << "  Ferramenta: nenhuma\n";
            }

            std::cout << "----\n";
        }
    }

    if (!encontrou) {
        std::cout << "As posições estão todas vazias.\n";
    }

    return true;
}

bool Jogo::colhe(char lChar, char cChar) {

    if (!jardim) {
        std::cout << "Ainda nao existe jardim.\n";
        return true;
    }

    int l, c;

    if (!letraParaIndice(lChar, cChar, l, c)) {
        std::cout << "Coordenadas invalidas.\n";
        return true;
    }

    if (l < 0 || l >= jardim->getLinhas() || c < 0 || c >= jardim->getColunas()) {
        std::cout << "Posicao fora dos limites.\n";
        return true;
    }

    if (!jardineiro.podeColher()) {
        std::cout << "Ja colheu o maximo neste turno.\n";
        return true;
    }

    Solo& s = jardim->getSolo(l, c);
    Planta* p = s.getPlanta();

    if (!p) {
        std::cout << "Nao existe planta nessa posicao.\n";
        return true;
    }

    s.setPlanta(nullptr);
    delete p;

    jardineiro.registaColheita();

    std::cout << "Planta colhida em "
              << ('a' + l) << ('a' + c)
              << ".\n";

    jardim->imprime();
    return true;
}

bool Jogo::grava(const std::string& nome) {
    if (!jardim) {
        std::cout << "Nao existe jardim.\n";
        return false;
    }

    auto it = backups.find(nome);
    if (it != backups.end()) {
        delete it->second;
        backups.erase(it);
    }

    backups[nome] = new Jardim(*jardim);
    std::cout << "Gravado: " << nome << "\n";
    return true;
}

bool Jogo::apaga(const std::string &nome) {

    auto it = backups.find(nome);
    if (it == backups.end()) {
        std::cout << "Gravacao inexistente.\n";
        return false;
    }

    delete it->second;
    backups.erase(it);

    std::cout << "Gravacao apagada.\n";
    return true;

}

bool Jogo::recupera(const std::string &nome) {

    auto it = backups.find(nome);
    if (it == backups.end()) {
        std::cout << "Gravacao inexistente.\n";
        return false;
    }

    delete jardim;
    jardim = new Jardim(*it->second);

    delete it->second;
    backups.erase(it);

    std::cout << "Jardim recuperado.\n";
    imprime();
    return true;

}
