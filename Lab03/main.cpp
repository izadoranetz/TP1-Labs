#include <iostream>
#include "dominios.hpp"

using namespace std;

int main() {

    // Teste de CodigoCliente
    CodigoCliente codigo;
    codigo.setValor(2);

    cout << "Codigo: " << codigo.getValor() << endl;

    CodigoCliente codigo2;
    codigo2.setValor(4);

    return 0;
}