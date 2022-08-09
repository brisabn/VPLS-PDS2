#include <iomanip>

#include "Pixel.hpp"
#include "Imagem.hpp"
using namespace std;

Pixel::Pixel() : Pixel(0, 0, 0)
{
}

Pixel::Pixel(int red, int green, int blue) : _red(red), _green(green), _blue(blue)
{
}

void Pixel::set_rgb(int red, int green, int blue)
{
    this->_red = red;
    this->_green = green;
    this->_blue = blue;
}

vector<int> Pixel::get_rgb()
{
    vector<int> cor = {this->_red, this->_green, this->_blue};
    return cor;
}

void Pixel::print()
{
    vector<int> cor = this->get_rgb();
    cout << setfill('0') << setw(3) << cor[0];
    cout << setfill('0') << setw(3) << cor[1];
    cout << setfill('0') << setw(3) << cor[2];
}

int Pixel::average_gray(vector<int> pixel)
{
    return (pixel[0] + pixel[1] + pixel[2]) / 3;
}