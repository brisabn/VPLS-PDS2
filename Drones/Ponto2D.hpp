#ifndef PONTO2D_H
#define PONTO2D_H

#include <iostream>
#include <sstream>
using namespace std;

struct Ponto2D
{
    double x, y;

    Ponto2D();
    Ponto2D(double x, double y);

    double calcular_distancia(Ponto2D *posicao);
    string get_dados();
};

#endif