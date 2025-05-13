#include <iostream>

#include "dominios.hpp"
#include "testes.hpp"
#include "entidades.hpp"

using namespace std;

int main() {

// rodar testes unitarios

    std::cout << "Iniciando os testes..." << std::endl;

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

    TUProfile profileTest;
    int profileResult = profileTest.run();
    if (profileResult == TUProfile::SUCCESS) {
        std::cout << "Teste de perfil: SUCESSO" << std::endl;
    } else {
        std::cout << "Teste de perfil: FALHA" << std::endl;
    }

    TUCpf cpfTest;
    int cpfResult = cpfTest.run();
    if (cpfResult == TUCpf::SUCCESS) {
        std::cout << "Teste de CPF: SUCESSO" << std::endl;
    } else {
        std::cout << "Teste de CPF: FALHA" << std::endl;
    }

    std::cout << "Testes concluidos." << std::endl;

    return 0;

}