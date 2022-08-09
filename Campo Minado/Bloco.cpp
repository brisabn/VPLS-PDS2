#include "Bloco.hpp"
#include <vector>
#include <string>

using namespace std;

Bloco::Bloco()
{
}

Bloco::~Bloco()
{
}

Bloco::Bloco(Coordenada _coord)
{
  this->coord = _coord;
}

bool Bloco::revelar(vector<vector<Bloco *>> &tabuleiro)
{
  vector<Coordenada> adj;
  revelado = true;
  coord.getCoordenadasAdjacentes(adj, tabuleiro.size(), tabuleiro.size());

  for (auto it : adj)
  {
    if (tabuleiro[it.getRow()][it.getCol()]->ehRevelado() == false)
    {
      tabuleiro[it.getRow()][it.getCol()]->revelar(tabuleiro);
    }
  }

  return true;
}

string Bloco::getSimbolo()
{
  if (revelado == false)
    return "#";
  else
  {
    if (valor == -1)
      return "*";
    else
      return to_string(valor);
  }
}

bool Bloco::ehRevelado()
{
  if (revelado == false)
    return false;
  else
    return true;
}

Coordenada Bloco::getCoord()
{
  return coord;
}

int Bloco::getValor()
{
  return valor;
}