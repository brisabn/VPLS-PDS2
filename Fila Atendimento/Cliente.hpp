#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <sstream>
using namespace std;

struct Cliente
{
    int _idade, _senha;
    string _nome;

    Cliente();
    Cliente(string nome, int idade, int senha);
    bool eh_prioritario();
    int tempo_estimado_atendimento();
    void imprimir_dados();
};

#endif