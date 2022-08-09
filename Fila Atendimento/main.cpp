#include "avaliacao_basica_atendimento.hpp"
#include "Cliente.hpp"
#include "FilaAtendimento.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{

    FilaAtendimento fila;
    Cliente cliente;
    char data;
    while (cin >> data)
    { // Lendo o caractere que define o comando

        // Executando o comando informado
        switch (data)
        {

        // Adicionar novo cliente
        case 'a':
            cin >> cliente._nome >> cliente._idade;
            fila.adicionar_cliente(cliente._nome, cliente._idade);
            break;

        // Chamar cliente
        case 'c':
            fila.chamar_cliente();
            break;

        // Imprimir estimativa de tempo de espera
        case 'e':
            cin >> cliente._senha;
            fila.estimativa_tempo_espera(cliente._senha);
            break;

        // Imprimir status da fila
        case 'p':
            fila.imprimir_fila();
            break;

            // Avaliação código
        case 'b':
            avaliacao_basica();
            break;
        }
    }
    return 0;
}