#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Pixel
{
private:
    int _red = 0;
    int _green = 0;
    int _blue = 0;

public:
    Pixel();
    Pixel(int red, int green, int blue);

    void set_rgb(int red, int green, int blue);
    vector<int> get_rgb();
    void print();
    int average_gray(vector<int> pixel);
};

#endif