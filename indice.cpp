#include <vector>
#include <iostream>
#include <string>
#include "indice.hpp"

double Indice::porcent(double total){
    return (quantRepeticoes/total);
}
void Indice::setTexto(string palavra){
    texto = palavra;
}
void Indice::aumentarRepeticoes(){
    quantRepeticoes++;
}
string Indice::getTexto(){
    return texto;
}
int Indice::getRepeticoes(){
    return quantRepeticoes;
}