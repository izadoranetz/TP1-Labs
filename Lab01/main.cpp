#include <iostream>
#include "dominios.hpp"

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

    // testando a classe CPF
    Cpf *meuCpf = new Cpf();

    //cpf valido
    if(meuCpf->setCpf("12345678900")) {
        cout << "CPF valido: " << meuCpf->getCpf() << endl;
    } else {
        cout << "CPF invalido: " << meuCpf->getCpf() << endl;
    }

    //cpf invalido
    if(meuCpf->setCpf("123abc45678")) {
        cout << "CPF valido: " << meuCpf->getCpf() << endl;
    } else {
        cout << "CPF invalido: " << meuCpf->getCpf() << endl;
    }

    delete meuCpf;

    // Criando como objeto (recomendado para casos simples)
    Profile perfil;

    try {
        perfil.setProfile("moderado");
        cout << "Perfil definido: " << perfil.getProfile() << endl;

        perfil.setProfile("invalido"); // Isso lançará exceção
    } catch (const invalid_argument& e) {
        cout << "Erro: " << e.what() << endl;
    }

    // Ou criando como ponteiro (se necessário)
    Profile* ptrPerfil = new Profile();
    try {
        ptrPerfil->setProfile("agressivo");
        cout << "Perfil definido: " << ptrPerfil->getProfile() << endl;
    } catch (...) {
        delete ptrPerfil;
        throw;
    }
    delete ptrPerfil;


    return 0;

}


