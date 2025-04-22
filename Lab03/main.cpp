#include <iostream>
#include "dominios.hpp"

using namespace std;

int main() {

    // Teste de CodigoCliente
    CodigoCliente codigo;

    codigo.setValor(2);

    cout << "Codigo: " << codigo.getValor() << endl;

    return 0;
}