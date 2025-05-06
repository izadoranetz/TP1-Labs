#include <iostream>

#include "dominios.hpp"
#include "testes.hpp"

using namespace std;

int main() {

// rodar testes unitarios

    TUDominio testeDominio;

    switch(testeDominio.run()){
        case TUDominio::SUCESSO:
            cout << "Teste de unidade passou!" << endl;
            break;
        case TUDominio::FALHA:
            cout << "Teste de unidade falhou!" << endl;
            break;
        default:
            cout << "Erro inesperado!" << endl;
    }

    return 0;

}