#include <iomanip>
#include <iostream>
#include <cstdlib>

#include "pokebola.hpp"

// inicializando o contator estático, que serve para todas pokebolas
int Pokebola::count = 0;
Pokebola::Pokebola()
{
  this->id = count;
  this->pokemon = nullptr;
  count++;
}

int Pokebola::getId()
{
  return this->id;
}

void Pokebola::guardarPokemon()
{
  if (pokemon != nullptr)
    pokemon->set_dormindo(true);
}

Pokemon *Pokebola::liberarPokemon()
{
  if (pokemon != nullptr)
  {
    pokemon->set_dormindo(false);
    return pokemon;
  }
  else
    return nullptr;
}

bool Pokebola::capturar(Pokemon &_pokemon)
{
  double sorte;
  sorte = ((double)rand() / (RAND_MAX));

  if (sorte > 0.5)
  {
    // pokemon capturado cria instância
    PokemonCapturado *poke_capturado = new PokemonCapturado(_pokemon);
    this->pokemon = poke_capturado;
    return true;
  }
  else
    return false;
}

PokemonCapturado *Pokebola::get_HasPokemon()
{
  return this->pokemon;
}