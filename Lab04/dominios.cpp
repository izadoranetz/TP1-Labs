#include "dominios.hpp"

void Dominio::validar(string valor){
    if (valor.empty()) {
        throw invalid_argument("Valor não pode ser vazio");
    }
    if (valor.length() > 50) {
        throw length_error("Valor muito longo");
    }
}

void Dominio::setValor(string valor){
    validar(valor);
    this->valor = valor;
}