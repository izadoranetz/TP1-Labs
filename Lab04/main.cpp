// refatorar código para uso de exceções

#include <iostream>
#include "dominios.hpp"

using namespace std;

int main() {
    cout << "Uso de Exceções: " << endl;
    

    Dominio dominio;
    
    try {
        dominio.setValor("300");
    }
    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << endl;
    }

    // validor invalido
    try {
        dominio.setValor("98023984902374983587634875634875638765384765837658736");
    }
    catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << endl;
    }

    return 0;
}