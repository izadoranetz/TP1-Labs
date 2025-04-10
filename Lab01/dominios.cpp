#include "dominios.hpp"
#include <algorithm>
#include <regex>

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


void Profile::setProfile(string profile) {
    static const regex pattern("^(conservador|moderado|agressivo)$");
    if(!regex_match(profile, pattern)) {
        throw invalid_argument("Perfil inválido. Deve ser 'conservador', 'moderado' ou 'agressivo'.");
    }

    if (profile == "conservador") {
        this->profile = conservador;
    } else if (profile == "moderado") {
        this->profile = moderado;
    } else {
        this->profile = agressivo;
    }
}

string Profile::getProfile() {
    switch(profile) {
        case conservador: return "conservador";
        case moderado: return "moderado";
        case agressivo: return "agressivo";
        default: return "";
    }
}

