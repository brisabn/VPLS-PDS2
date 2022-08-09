#ifndef EVOLUTIONBALL_H
#define EVOLUTIONBALL_H

#include <iostream>
#include <iomanip>
#include "pokebola.hpp"

class EvolutionBall : public Pokebola
{
private:
    double taxaPoder;
    bool habilidadeUsada = false;

public:
    EvolutionBall(double _taxaPoder);
    bool evoluirPokemon();
};

#endif