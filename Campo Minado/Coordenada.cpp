#include "Coordenada.hpp"

Coordenada::Coordenada()
{
}

Coordenada::Coordenada(int _row, int _col)
{
  this->row = _row;
  this->col = _col;
}

void Coordenada::getCoordenadasAdjacentes(vector<Coordenada> &adjacentes, int rowBoundary, int colBoundary)
{

  rowBoundary--;
  colBoundary--;
  int t, s, i, j;

  if (row > 0)
    i = row - 1;
  else
    i = row;
  if (col > 0)
    j = col - 1;
  else
    j = col;

  for (t = i; t <= row + 1 && t <= rowBoundary; t++)
  {
    Coordenada coord;
    coord.row = t;
    for (s = j; s <= col + 1 && s <= colBoundary; s++)
    {
      coord.col = s;
      adjacentes.push_back(coord);
    }
  }
}

int Coordenada::getRow()
{
  return row;
}

int Coordenada::getCol()
{
  return col;
}