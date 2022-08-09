#ifndef POKEMONCAPTURADO_H
#define POKEMONCAPTURADO_H

#include <iostream>
#include "pokemon.hpp"

class PokemonCapturado : public Pokemon
{

private:
    bool evoluido;
    bool dormindo;

public:
    PokemonCapturado(Pokemon &_pok);

    void evoluir(double taxaPoder);
    void set_dormindo(bool mimir);
    void set_evoluido(bool evol);
};

#endif