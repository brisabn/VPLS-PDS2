#ifndef BLOCOMINA_H
#define BLOCOMINA_H

#include "Bloco.hpp"
using namespace std;

class BlocoMina : public Bloco
{

public:
    BlocoMina();
    BlocoMina(vector<vector<Bloco *>> &tabuleiro, Coordenada _coord);
    virtual bool revelar(vector<vector<Bloco *>> &tabuleiro) override;
    virtual ~BlocoMina();
};

#endif