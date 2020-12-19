#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include "indice.cpp"
using namespace std;

string transMinuscula(string s)
{
    string retorno = s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < 91)
        {
            retorno[i] = s[i] + 32;
        }
        else
            retorno[i] = s[i];
    }
    return retorno;
}

int main()
{
    string auxiliar;
    int m=0;
    string texto = "";
    while (cin >> auxiliar) {
        texto += auxiliar;
        texto += " ";
	}
    texto += "\n";
    vector<Indice> tokens;
    istringstream tokenizer(texto);
    string token;
    int totalPalavras = 0;
    while (tokenizer >> token)
    {
        totalPalavras++;
        Indice novoToken;
        bool palavraExiste = false;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i].getTexto() == token)
            {
                palavraExiste = true;
                tokens[i].aumentarRepeticoes();
            }
        }
        if (!palavraExiste)
        {
            novoToken.setTexto(transMinuscula(token));
            novoToken.aumentarRepeticoes();
            tokens.push_back(novoToken);
        }
    }
    vector<string> vecOrdenado;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i].getTexto().size() >= 3)
        {
            vecOrdenado.push_back(tokens[i].getTexto());
        }
    }
    sort(vecOrdenado.begin(), vecOrdenado.begin() + vecOrdenado.size());
    cout << fixed;
    cout << setprecision(2);
    for (int i = 0; i < vecOrdenado.size(); i++)
    {
        for (int j = 0; j < tokens.size(); j++)
        {
            if (vecOrdenado[i] == tokens[j].getTexto())
            {
                cout << tokens[j].getTexto() << " " << tokens[j].getRepeticoes() << " " << tokens[j].porcent(totalPalavras) << endl;
            }
        }
    }
    return 0;
}