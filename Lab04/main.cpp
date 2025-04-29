#include <iostream>
#include "dominios.hpp"

using namespace std;

int main() {
    cout << "Uso de Exceções: " << endl;

    Dominio dominio;
    
    // Teste com valor válido
    try {
        dominio.setValor("300");
        cout << "Valor válido definido: " << dominio.getValor() << endl;
    }
    catch(invalid_argument &exp) {
        cout << "Excecao (invalid_argument): " << exp.what() << endl;
    }
    catch(length_error &exp) {
        cout << "Excecao (length_error): " << exp.what() << endl;
    }
    catch(...) {
        cout << "Excecao desconhecida" << endl;
    }

    // Teste com valor inválido (muito longo)
    try {
        dominio.setValor("98023984902374983587634875634875638765384765837658736");
        cout << "Valor válido definido: " << dominio.getValor() << endl;
    }
    catch(invalid_argument &exp) {
        cout << "Excecao (invalid_argument): " << exp.what() << endl;
    }
    catch(length_error &exp) {
        cout << "Excecao (length_error): " << exp.what() << endl;
    }
    catch(...) {
        cout << "Excecao desconhecida" << endl;
    }



}