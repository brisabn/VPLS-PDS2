#include <iomanip>
#include <iostream>
#include <string>

#include "pokemonCapturado.hpp"

PokemonCapturado::PokemonCapturado(Pokemon &_pok) : Pokemon(_pok)
{
  evoluido = false;
  dormindo = true;

  // passei o parametro la no hpp de pokemon
}

void PokemonCapturado::evoluir(double taxaPoder)
{
  evoluido = true;
  nome = proxEvolucao;
  proxEvolucao = " ";
  forcaAtaque = (taxaPoder * forcaAtaque) + forcaAtaque;
  forcaDefesa = (taxaPoder * forcaDefesa) + forcaDefesa;
}

void PokemonCapturado::set_dormindo(bool mimir)
{
  this->dormindo = mimir;
}