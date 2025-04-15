#include "dominios.hpp"

bool Codigo::validar(int codigo){
    if(codigo > LIMITE)
        return false;
    return true;
}

bool Codigo::setValor(int valor){
    if(!validar(valor))
        return false;
    this->valor = valor;
    return true;
}

bool Prioridade::validar(int valor){
    if(valor == INVALIDO)
        return false;
    return true;
}

bool Prioridade::setValor(int valor){
    if(!validar(valor))
        return false;
    this->valor = valor;
    return true;
}
