#include <iomanip>
#include <iostream>

#include "pokemon.hpp"

using namespace std;

Pokemon::Pokemon() {}

Pokemon::Pokemon(string _nome, string _tipo, string _pEvol, double _fA, double _fD, double _saude)
{
  this->nome = _nome;
  this->tipo = _tipo;
  this->saude = _saude;
  this->forcaAtaque = _fA;
  this->forcaDefesa = _fD;
  this->proxEvolucao = _pEvol;
}

string Pokemon::getNome()
{
  return nome;
}

void Pokemon::maxSaude()
{
  saude = 100;
}

void Pokemon::info()
{
  cout << "Pokemon: " << nome << ", " << tipo << ", " << forcaAtaque << ", " << forcaDefesa << ", " << saude << endl;
}
