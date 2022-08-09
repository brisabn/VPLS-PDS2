#include "BlocoMina.hpp"
#include "BlocoContador.hpp"

BlocoMina::BlocoMina()
{
  this->valor = -1;
}

BlocoMina::~BlocoMina()
{
}

BlocoMina::BlocoMina(vector<vector<Bloco *>> &tabuleiro, Coordenada _coord)
{
  vector<Coordenada> adj;
  this->valor = -1;

  _coord.getCoordenadasAdjacentes(adj, tabuleiro.size(), tabuleiro.size());

  for (auto adjacente : adj)
  {

    if (tabuleiro[adjacente.getRow()][adjacente.getCol()]->getValor() > 0)
    {
      (tabuleiro[adjacente.getRow()][adjacente.getCol()])->valor++;
      /* Bloco* b = new BlocoContador(coord);
        BlocoContador* bc = dynamic_cast<BlocoContador*>(b);
        bc->incrementarValor();
        tabuleiro[adjacente.getRow()][adjacente.getCol()] = bc;
        // dando segmentation fault :(
        delete b;  */
    }
    else if ((tabuleiro[adjacente.getRow()][adjacente.getCol()])->getValor() == 0)
    {
      (tabuleiro[adjacente.getRow()][adjacente.getCol()]) = new BlocoContador(coord);
      (tabuleiro[adjacente.getRow()][adjacente.getCol()])->valor++;
    }
  }
}

bool BlocoMina::revelar(vector<vector<Bloco *>> &tabuleiro)
{

  for (unsigned int l = 0; l < tabuleiro.size(); l++)
  {
    for (unsigned int c = 0; c < tabuleiro.size(); c++)
    {
      tabuleiro[l][c]->revelado = true;
    }
  }
  return false;
}