#include <iostream>
#include "dominios.hpp"
#include "tests.hpp"

using namespace std;

int main()
{
    // testando a classe CodigoCliente
    CodigoCliente *ptra;

    ptra = new CodigoCliente();
    if(ptra->setValor(3))
        cout <<"Valor = " << ptra->getValor() <<endl;
    else
        cout << "Valor invalido" <<endl;
    if(ptra->setValor(30))
        cout << "Valor = " << ptra->getValor() <<endl;
    else
    cout<<"Valor invalido"<<endl;
    delete ptra;

    // Testes de CPFs validos
    testCpf("52998224725");  // CPF valido

    // Testes de CPFs invalidos
    testCpf("00000000000");  // todos d�gitos iguais
    testCpf("12345678901");  // invalido (digitos verificadores incorretos)
    testCpf("123");          // Muito curto
    testCpf("1234567890123"); // Muito longo
    testCpf("ABC12345678");  // Caracteres n�o num�ricos
    testCpf("52998224724");  // D�gito verificador incorreto
    testCpf("");             // String vazia


    Profile perfil;
    try {
        perfil.setProfile("moderado");
        cout << "Perfil definido: " << perfil.getProfile() << endl;
        perfil.setProfile("invalido");
    } catch (const invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }



    return 0;

}


