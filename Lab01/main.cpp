#include <iostream>
#include "dominios.hpp"

using namespace std;

int main()
{
    CodigoCliente a;

    if(a.setValor(3))
        cout<<"Valor = "<<a.getValor()<<endl;
    else
        cout<<"Valor invalido"<<endl;
    if(a.setValor(30))
        cout<<"Valor = "<<a.getValor()<<endl;
    else
    cout<<"Valor invalido"<<endl;
    return 0;

}
