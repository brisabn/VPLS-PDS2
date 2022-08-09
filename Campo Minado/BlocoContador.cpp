#include "BlocoContador.hpp"

BlocoContador::BlocoContador(Coordenada _coord)
{
  this->coord = _coord;
}

BlocoContador::~BlocoContador()
{
}

bool BlocoContador::revelar(vector<vector<Bloco *>> &tabuleiro)
{
  this->revelado = true;
  return revelado;
}

void BlocoContador::incrementarValor()
{
  valor++;
}