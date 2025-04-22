#include "dominios.hpp"

bool Codigo::setValor(int valor){
    if(!validar(valor))
        return false;
    this->valor = valor;
    return true;
}

// teste de validação: pode ser qualquer valor menos 4
bool CodigoCliente::validar(int valor){
    if(valor == 4)
        return false;
    return true;
}