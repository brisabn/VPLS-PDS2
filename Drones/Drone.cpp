#include <sstream>
#include <iomanip>
#include <math.h>

#include "Drone.hpp"
#include "Ponto2D.hpp"
using namespace std;

Drone::Drone()
{
}

Drone::Drone(int id, Ponto2D posicao, double raio)
{
    this->id = id;
    this->raio = raio;
    this->posicao = posicao;
}

void Drone::mover(double v, double th, double t)
{
    double desloc = 0;

    desloc = desloc + v * t;

    this->posicao.x = posicao.x + desloc * cos(th);
    this->posicao.y = posicao.y + desloc * sin(th);

    _energia = _energia - desloc;

    if (_energia <= 50)
        cout << "Alerta, energia baixa!" << endl;
}

double Drone::calcular_distancia(Drone *drone)
{
    double d;
    d = this->posicao.calcular_distancia(&drone->posicao);
    return d;
}

void Drone::broadcast_mensagem(Drone **drones, int n)
{
    string mensagem;
    ostringstream anotar_mensagem;

    int i;
    for (i = 0; i <= n; i++)
    {
        if ((calcular_distancia(drones[i]) <= raio) && (drones[i]->id != id))
        {
            anotar_mensagem << "Drone: " << id << ", Posição:" << posicao.get_dados() << endl;
            mensagem = anotar_mensagem.str();
            drones[i]->salvar_mensagem(mensagem);
            anotar_mensagem.str("");
            anotar_mensagem.clear();
        }
    }
}

void Drone::salvar_mensagem(string mensagem)
{
    this->buffer[this->buffer_position] = mensagem;
    this->buffer_position++;
    if (this->buffer_position >= 5)
        this->buffer_position = 0;
}

void Drone::imprimir_mensagens_recebidas()
{
    int i;
    cout << "Mensagens de " << this->id << ":" << endl;
    for (i = 0; i < 5; i++)
    {
        cout << buffer[i];
    }
}

void Drone::imprimir_status()
{
    cout << this->id << "\t" << this->posicao.x << "\t" << this->posicao.y << "\t" << this->_energia << endl;
}