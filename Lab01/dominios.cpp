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


/**
 * @brief Valida o CPF informado.
 * @param cpf CPF a ser validado conforme a norma oficial.
 * @throw std::invalid_argument Se o CPF for inválido.
 */

bool Cpf::validateCpf(string cpf){

    // verifica se tem 11 digitos
    if(cpf.length() != 11 ||
       !std::all_of(cpf.begin(), cpf.end(), ::isdigit)) {
        return false;
    }

    // verifica se todos caracteres sao iguais
    if (cpf.find_first_not_of(cpf[0]) == std::string::npos) {
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



return true;

}

/**
 * @brief Define o CPF após validação.
 * @param cpf CPF a ser validado (formato "XXX.XXX.XXX-XX", seguindo norma oficial do CPF).
 * @throw std::invalid_argument Se o CPF for inválido.
 */

void Cpf::setCpf(string cpf) {
    if(!validateCpf(cpf)) {
        throw invalid_argument("Cpf invalido");
    }
    this->cpf = cpf;
}

/**
 * @brief Retorna o CPF armazenado.
 * @return std::string CPF no formato "XXX.XXX.XXX-XX".
 */

string Cpf::getCpf() {
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

