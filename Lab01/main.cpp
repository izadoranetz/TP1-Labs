#include <iostream>
#include "dominios.hpp"

using namespace std;

int main()
{
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

    // testando a classe CPF
    Cpf *meuCpf = new Cpf();

    //cpf valido
    if(meuCpf->setCpf("12345678900")) {
        cout << "CPF valido: " << meuCpf->getCpf() << endl;
    } else {
        cout << "CPF inválido: " << meuCpf->getCpf() << endl;
    }

    //cpf invalido
    if(meuCpf->setCpf("123abc45678")) {
        cout << "CPF válido: " << meuCpf->getCpf() << endl;
    } else {
        cout << "CPF invalido: " << meuCpf->getCpf() << endl;
    }

    delete meuCpf;

    return 0;

}


