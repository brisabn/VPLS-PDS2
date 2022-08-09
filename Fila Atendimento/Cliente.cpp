#include <iostream>
#include <sstream>

#include "Cliente.hpp"
using namespace std;

Cliente::Cliente()
{
}

Cliente::Cliente(string nome, int idade, int senha)
{
    this->_nome = nome;
    this->_idade = idade;
    this->_senha = senha;
}

bool Cliente::eh_prioritario()
{
    if (this->_idade >= 60)
        return true;
    else
        return false;
}

int Cliente::tempo_estimado_atendimento()
{
    int tempo;

    if (this->eh_prioritario() == true)
        tempo = 12;
    else
        tempo = 8;

    return tempo;
}

void Cliente::imprimir_dados()
{
    cout << this->_senha << "\t" << this->_nome << "\t" << this->_idade << endl;
}