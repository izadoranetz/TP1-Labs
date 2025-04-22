#include "dominios.hpp"

bool Codigo::setValor(string valor) {
    if(!validar(valor))
        return false;
    this->valor = valor;
    return true;
}