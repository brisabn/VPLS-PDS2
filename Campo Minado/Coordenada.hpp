#ifndef COORDENADA_H
#define COORDENADA_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Coordenada
{
private:
    int row;
    int col;

public:
    Coordenada();
    Coordenada(int _row, int _col);
    void getCoordenadasAdjacentes(vector<Coordenada> &adjacentes, int rowBoundary, int colBoundary);
    int getRow();
    int getCol();
};

#endif