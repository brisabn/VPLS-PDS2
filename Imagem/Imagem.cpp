#include <sstream>
#include <iomanip>
#include <math.h>

#include "Pixel.hpp"
#include "Imagem.hpp"
using namespace std;

Imagem::Imagem()
{
}

void Imagem::initialize_image(int width, int height)
{
    this->_width = width;
    this->_height = height;

    Pixel pixel;
    this->_image.resize(height, vector<Pixel>(width, pixel));
}

void Imagem::fill(int row, int col, string pixel)
{
    string vermelho = pixel.substr(0, 3);
    string verde = pixel.substr(3, 3);
    string azul = pixel.substr(6, 3);

    _image[row][col].set_rgb(stoi(vermelho), stoi(verde), stoi(azul));
}

void Imagem::to_grayscale()
{
    int i, j;
    for (i = 0; i < this->_width; i++)
    {
        for (j = 0; j < this->_height; j++)
        {
            vector<int> pixel = _image[i][j].get_rgb();
            int gray = _image[i][j].average_gray(pixel);
            _image[i][j].set_rgb(gray, gray, gray);
        }
    }
}

void Imagem::grayscale_thresholding(int lim)
{
    int i, j;
    for (i = 0; i < this->_width; i++)
    {
        for (j = 0; j < this->_height; j++)
        {
            vector<int> pixel = _image[i][j].get_rgb();
            int gray = _image[i][j].average_gray(pixel);
            if (gray > lim)
                gray = 255;
            else
                gray = 000;

            _image[i][j].set_rgb(gray, gray, gray);
        }
    }
}

void Imagem::show()
{
    int i, j;
    for (i = 0; i < this->_width; i++)
    {
        for (j = 0; j < this->_height; j++)
        {
            _image[i][j].print();
            cout << " ";
        }
        cout << endl;
    }
}
