#ifndef BLOCO_H
#define BLOCO_H

#include "Coordenada.hpp"

class Bloco
{
public:
    Coordenada coord;
    bool revelado = false;
    int valor = 0;

public:
    Bloco();
    Bloco(Coordenada _coord);
    virtual ~Bloco();
    virtual bool revelar(vector<vector<Bloco *>> &tabuleiro);
    string getSimbolo();
    bool ehRevelado();
    Coordenada getCoord();
    int getValor();
};

#endif