#ifndef CSV_H
#define CSV_H

#include <iostream>
#include <iomanip>
#include "file.hpp"

class CSV : public File
{
private:
    void split(string &str, vector<string> &out);

    // Funções utilizadas no main
public:
    string getHeader(IReadable &object);
    virtual void readLine(string &head, string &line, IReadable &object) override;
    virtual string write(IReadable &object) override;
};

#endif
