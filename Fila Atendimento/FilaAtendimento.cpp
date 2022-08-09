#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>

#include "Cliente.hpp"
#include "FilaAtendimento.hpp"

using namespace std;

void FilaAtendimento::adicionar_cliente(string nome, int idade)
{
    Cliente cliente = Cliente(nome, idade, this->senha_fila);

    if (cliente.eh_prioritario() == true)
    {
        Fila_P.insertNode(cliente);
    }
    else
        Fila_NP.insertNode(cliente);

    this->senha_fila++;
}

Cliente *FilaAtendimento::chamar_cliente()
{

    if (this->Fila_P.head != nullptr)
        return Fila_P.removeNode();
    if ((this->Fila_P.head == nullptr) && (this->Fila_NP.head != nullptr))
        return Fila_NP.removeNode();
    if ((this->Fila_P.head == nullptr) && (this->Fila_NP.head == nullptr))
        cout << "Fila vazia!" << endl;

    return 0;
}

void FilaAtendimento::estimativa_tempo_espera(int senha_fila)
{
    int X = 0, Y = 0;

    if (Fila_P.head != nullptr)
    {
        Node *aux = Fila_P.head;
        while ((aux != nullptr) && (aux->cliente._senha != senha_fila))
        {
            X = X + aux->cliente.tempo_estimado_atendimento();
            aux = aux->next;
        }
        if (aux != nullptr)
            cout << "Tempo estimado para atender " << aux->cliente._nome << " eh " << X << " minutos." << endl;

        else
        {
            aux = Fila_NP.head;
            while ((aux != nullptr) && (aux->cliente._senha != senha_fila))
            {
                Y = Y + aux->cliente.tempo_estimado_atendimento();
                aux = aux->next;
            }
            cout << "Tempo estimado para atender " << aux->cliente._nome << " eh " << X + Y << " minutos." << endl;
        }
    }

    else
    {
        Node *aux = Fila_NP.head;
        while ((aux != nullptr) && (aux->cliente._senha != senha_fila))
        {
            Y = Y + aux->cliente.tempo_estimado_atendimento();
            aux = aux->next;
        }
        cout << "Tempo estimado para atender " << aux->cliente._nome << " eh " << Y << " minutos." << endl;
    }
}

void FilaAtendimento::imprimir_fila()
{
    Node *aux1 = Fila_P.head;

    while (aux1 != nullptr)
    {
        aux1->cliente.imprimir_dados();
        aux1 = aux1->next;
    }

    Node *aux2 = Fila_NP.head;

    while (aux2 != nullptr)
    {
        aux2->cliente.imprimir_dados();
        aux2 = aux2->next;
    }
}