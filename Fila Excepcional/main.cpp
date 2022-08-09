#include "avaliacao_basica_excecoes.hpp"

#include <iostream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

int main()
{

  LimitedQueue fila;

  int k;
  char data;
  while (cin >> data)
  {
    // Executando o comando informado
    switch (data)
    {

    //  Inicializa a fila com um tamanho máximo
    case 'i':
      try
      {
        cin >> k;
        fila = LimitedQueue(k);
      }
      catch (InvalidSizeException &e)
      {
        cerr << "Excecao: " << e.name << endl;
      }
      break;

      //  Insere o inteiro k no final da fila.
    case 'p':
      cin >> k;
      try
      {
        fila.push_back(k);
      }
      catch (QueueFullException &e)
      {
        cerr << "Excecao: " << e.name << endl;
      }
      break;

    // Remove o primeiro elemento da fila
    case 'o':
      try
      {
        fila.pop_front();
      }
      catch (QueueEmptyException &e)
      {
        cerr << "Excecao: " << e.name << endl;
      }
      break;

    // Imprime o primeiro elemento da fila.
    case 'f':
      try
      {
        cout << fila.front();
      }
      catch (QueueEmptyException &e)
      {
        cerr << "Excecao: " << e.name << endl;
      }
      break;

    // Imprime o último elemento da fila
    case 'l':
      try
      {
        cout << fila.back();
      }
      catch (QueueEmptyException &e)
      {
        cerr << "Excecao: " << e.name << endl;
      }
      break;

    // Imprime a fila toda
    case 'm':
      try
      {
        fila.print();
      }
      catch (QueueEmptyException &e)
      {
        cerr << "Excecao: " << e.name << endl;
      }
      break;

      // Busca k na fila e imprime sua posição
    case 'd':
      try
      {
        cin >> k;
        cout << fila.find(k) << endl;
      }
      catch (QueueEmptyException &e)
      {
        cerr << "Excecao: " << e.name << endl;
      }
      catch (ItemNotFoundException &e)
      {
        cerr << "Excecao: " << e.name << endl;
      }
      break;

      // Avaliação código
    case 'b':
      try
      {
        avaliacao_basica();
      }
      catch (QueueEmptyException &e)
      {
        cerr << "Excecao: " << e.name << endl;
      }
      catch (ItemNotFoundException &e)
      {
        cerr << "Excecao: " << e.name << endl;
      }
      catch (QueueFullException &e)
      {
        cerr << "Excecao: " << e.name << endl;
      }

      break;
    }
  }

  return 0;
}
