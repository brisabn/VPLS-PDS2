#include "avaliacao_basica_imagem.hpp"
#include "Imagem.hpp"
#include "Pixel.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{

    Imagem imagem;
    Pixel pixar;
    char data;
    int width, height, lim, i, j;
    string pixel;
    while (cin >> data)
    { // Lendo o caractere que define o comando

        // Executando o comando informado
        switch (data)
        {

        // Adicionar novo cliente
        case 'i':
            cin >> width >> height;
            imagem.initialize_image(width, height);
            break;

        // Preencher uma matriz
        case 'p':
            for (i = 0; i < width; i++)
            {
                for (j = 0; j < height; j++)
                {
                    cin >> pixel;
                    imagem.fill(i, j, pixel);
                }
            }
            break;

        // Exibir imagem
        case 's':
            imagem.show();
            break;

        // Transformar em escala cinza
        case 'g':
            imagem.to_grayscale();
            break;

        // Imprimir status da fila
        case 't':
            cin >> lim;
            imagem.grayscale_thresholding(lim);
            break;

            // Avaliação código
        case 'b':
            avaliacao_basica();
            break;
        }
    }
    return 0;
}