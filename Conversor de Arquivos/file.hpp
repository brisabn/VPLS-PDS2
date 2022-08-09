#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "ireadable.hpp"
using namespace std;

class File
{

public:
    virtual void readLine(string &head, string &line, IReadable &object) = 0;
    virtual string write(IReadable &object) = 0;
};

#endif