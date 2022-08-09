#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include "Ponto2D.hpp"
using namespace std;

struct Drone
{
    int id;
    double raio;
    Ponto2D posicao;
    string buffer[5];
    int buffer_position = 0;
    double _energia = 100;

    Drone();
    Drone(int id, Ponto2D posicao, double raio);

    void mover(double v, double th, double t);

    double calcular_distancia(Drone *drone);

    void broadcast_mensagem(Drone **drones, int n);

    void salvar_mensagem(string mensagem);

    void imprimir_mensagens_recebidas();

    void imprimir_status();
};

#endif