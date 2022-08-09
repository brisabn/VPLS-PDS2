#include <iomanip>
#include <iostream>
#include <ctime>

#include "healthBall.hpp"

HealthBall::HealthBall(double _intervalo)
{
  this->intervalo = _intervalo;
}

bool HealthBall::recuperarPokemon()
{
  time_t agora;
  time(&agora);

  if (pokemon == nullptr)
    return false;
  else
  {
    if (difftime(agora, ultimoUso) > intervalo)
    {
      pokemon->maxSaude();
      ultimoUso = agora;
      return true;
    }
    else
      return false;
  }
}