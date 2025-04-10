#include "dominios.hpp"
#include <algorithm>

bool CodigoCliente::validar(int valor){
if(valor>LIMITE)
    return false;
return true;
}

bool CodigoCliente::setValor(int valor){
if (!validar(valor))
    return false;
this-> valor = valor;
return true;
}


bool Cpf::validar(const std::string& cpf){
// verifica tamanho de 11 digitos
// incluir verificacao se cpf nao eh composto de numeros repetidos
if(cpf.length() != 11 ||
   !std::all_of(cpf.begin(), cpf.end(), ::isdigit)) {
    return false;
}
// transformar a string em um array de numeros

// verifica o primeiro digito
// separar os 9 primeiros digitos
// multiplicar cada um dos numeros, da direita para esquerda, por numeros crescentes a partir do numero do
// pegar o resultado e dividir por 11
// se o resto da divisao for menor que 2, o digito 1 é igual a zero
// se o resto da divisao for maior ou igual a 2, entao o digito é igual a 11 - resto

// verifica o segundo digito
//


return true;

}

bool Cpf::setCpf(const std::string& cpf){
if (!validar(cpf))
    return false;
this->cpf = cpf;
return true;
}

std::string Cpf::getCpf() const {
return cpf;
}


bool Perfill::validar(const std::string& perfil){
if (!validar(perfil))
    return false;
this->perfil = perfil;
return true;
}

bool Perfil::setPerfil(const std::string& perfil) {
    // iniciar array puxando a lista de perfis
    // Perfis array[3];
    // Perfis *perfis = std::find(std::begin(array)
};
