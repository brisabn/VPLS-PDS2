#ifndef TREINADOR_H
#define TREINADOR_H

#include <iostream>
#include <vector>
#include "healthBall.hpp"
#include "evolutionBall.hpp"
#include "pokemon.hpp"
#include "pokemonCapturado.hpp"
#include "pokebola.hpp"

using namespace std;

class Treinador
{
private:
    string nome;
    vector<EvolutionBall *> evolution_balls;
    vector<HealthBall *> health_balls;

public:
    Treinador(string _nome);
    ~Treinador();

    HealthBall *selecionarHealthBall(int _id);
    EvolutionBall *selecionarEvolBall(int _id);
    void adicionarPokebola(HealthBall *poke);
    void adicionarPokebola(EvolutionBall *poke);
    void listarPokemons();
};

#endif