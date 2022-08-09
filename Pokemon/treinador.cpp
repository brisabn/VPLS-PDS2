#include <iomanip>
#include <iostream>
#include <vector>

#include "treinador.hpp"

using namespace std;

Treinador::Treinador(string _nome)
{
  this->nome = _nome;
}
Treinador::~Treinador() {}

HealthBall *Treinador::selecionarHealthBall(int _id)
{
  // procura a pokebola com a _id
  for (HealthBall *curab : health_balls)
  {
    if (_id == curab->getId())
      return curab;
  }

  return nullptr;
}

EvolutionBall *Treinador::selecionarEvolBall(int _id)
{
  // procura a pokebola com a _id
  for (EvolutionBall *evolb : evolution_balls)
  {
    if (_id == evolb->getId())
      return evolb;
  }

  return nullptr;
}

void Treinador::adicionarPokebola(HealthBall *pokebola)
{
  health_balls.push_back(pokebola);
}

void Treinador::adicionarPokebola(EvolutionBall *pokebola)
{
  evolution_balls.push_back(pokebola);
}

void Treinador::listarPokemons()
{
  if (evolution_balls.empty() && health_balls.empty())
  {
    cout << "Treinador: " << nome << endl
         << "O treinador não possui pokebolas" << endl;
  }
  else
  {
    cout << "Treinador: " << nome << endl;

    // HealthBall
    for (HealthBall *curab : health_balls)
    {
      cout << "HealthBall ID: " << curab->getId() << endl;
      // expõe dados do pokemon
      if (curab->get_HasPokemon() != nullptr)
        (curab->get_HasPokemon())->info();
      else
        cout << "A pokebola não possui um pokemon" << endl;
    }

    // EvolutionBall
    for (EvolutionBall *evolb : evolution_balls)
    {
      cout << "EvolutionBall ID: " << evolb->getId() << endl;
      // expõe dados do pokemon
      if (evolb->get_HasPokemon() != nullptr)
        (evolb->get_HasPokemon())->info();
      else
        cout << "A pokebola não possui um pokemon" << endl;
    }
  }
}
