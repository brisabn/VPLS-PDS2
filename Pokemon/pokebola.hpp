#ifndef POKEBOLA_H
#define POKEBOLA_H

#include <iostream>
#include "pokemonCapturado.hpp"
#include "pokemon.hpp"

class Pokebola
{
private:
    static int count;

protected:
    int id;
    PokemonCapturado *pokemon;

public:
    Pokebola();
    ~Pokebola();

    int getId();
    void guardarPokemon();
    Pokemon *liberarPokemon();
    bool capturar(Pokemon &_pokemon);

    PokemonCapturado *get_HasPokemon();
};

#endif