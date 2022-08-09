#ifndef FILA_H
#define FILA_H

#include <iostream>
#include <sstream>
#include "Cliente.hpp"
using namespace std;

struct Node
{
    Cliente cliente;
    Node *next;
};

struct List
{
    Node *head = nullptr;
    Node *tail = nullptr;

    void insertNode(Cliente cliente)
    {
        Node *aux = new Node;
        aux->cliente = cliente;
        aux->next = nullptr;
        if (head == nullptr)
        {
            head = aux;
            tail = aux;
        }
        else
        {
            tail->next = aux;
            tail = aux;
        }
    }

    Cliente *removeNode()
    {
        Node *aux = this->head;
        this->head = head->next;

        return &aux->cliente;
    }
};

struct FilaAtendimento
{
    void adicionar_cliente(string nome, int idade);
    Cliente *chamar_cliente();
    void estimativa_tempo_espera(int senha);
    void imprimir_fila();

    int senha_fila = 1;

    List Fila_P;
    List Fila_NP;
};

#endif