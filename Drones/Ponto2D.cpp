#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>

#include "Drone.hpp"
#include "Ponto2D.hpp"
using namespace std;

Ponto2D::Ponto2D()
{
}

Ponto2D::Ponto2D(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Ponto2D::calcular_distancia(Ponto2D *ponto)
{
    double distancia;
    distancia = sqrt(pow((x - ponto->x), 2) + pow((y - ponto->y), 2));
    return abs(distancia);
}

string Ponto2D::get_dados()
{
    string dados;
    ostringstream anotar_dados;

    anotar_dados << "[" << fixed << setprecision(2) << x << " ," << y << "]";
    dados = anotar_dados.str();

    return dados;
}