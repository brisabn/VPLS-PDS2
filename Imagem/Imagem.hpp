#ifndef IMAGEM_H
#define IMAGEM_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Pixel.hpp"

using namespace std;

class Imagem
{
private:
    int _width, _height;
    vector<vector<Pixel>> _image;

public:
    Imagem();
    void initialize_image(int width, int height);
    void fill(int row, int col, string pixel);
    void to_grayscale();
    void grayscale_thresholding(int lim);
    void show();
};

#endif