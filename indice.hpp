#ifndef INDICE_HPP
#define INDICE_HPP

#include <string>

using namespace std;

class Indice{
    private:
        string texto;
        int quantRepeticoes = 0;
    public:
        void setTexto(string);
        void aumentarRepeticoes();
        double porcent(double);
        string getTexto();
        int getRepeticoes();
};


#endif