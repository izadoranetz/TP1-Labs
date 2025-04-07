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

    return 0;

}


