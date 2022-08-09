#include <iomanip>
#include <iostream>

#include "evolutionBall.hpp"

EvolutionBall::EvolutionBall(double _taxaPoder)
{
    this->taxaPoder = _taxaPoder;
}

bool EvolutionBall::evoluirPokemon()
{
    if (pokemon == nullptr)
        return false;
    else
    {
        if (!habilidadeUsada)
        {
            habilidadeUsada = true;
            pokemon->evoluir(taxaPoder);
            return true;
        }
        else
            return false;
    }
}