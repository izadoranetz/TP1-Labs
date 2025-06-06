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
 * @throw std::invalid_argument Se o CPF for inv�lido.
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

    // array dos digitos do cpf
    std::array<int, 11> digits;
    for (size_t i = 0; i < cpf.length(); i++) {
        digits[i] = cpf[i] - '0';
    }

    // verifica o primeiro digito
    // multiplica os 9 primeiros digitos, da direita para esquerda, por numeros crescentes a partir de 2
    int weight = 10;
    int sum = 0;
    for (size_t i = 0; i < 9; i++){
        sum += (digits[i]*weight);
        weight--;
    }
    // pegar o resultado e dividir por 11
    // se o resto da divisao for menor que 2, o digito eh igual a zero
    // se o resto da divisao for maior ou igual a 2, entao o digito eh igual a 11 - resto
    int rem = sum % 11;
    int first_digit;
    if(rem < 2){
        first_digit= 0;
    } else {
        first_digit= 11 - rem;
    }

    if(first_digit != digits[9]){
        return false;
    }

    // verifica o segundo digito, com calculo igual ao anterior, mas incluindo o primeiro digito
    weight = 11;
    sum = 0;
    for (size_t i = 0; i < 10; i++){
        sum += (digits[i]*weight);
        weight--;
    }
    rem = sum % 11;
    int second_digit;
    if(rem < 2){
        second_digit= 0;
    } else {
        second_digit= 11 - rem;
    }

    if(second_digit != digits[10]){
        return false;
    }

return true;

}

/**
 * @brief Define o CPF ap�s valida��o.
 * @param cpf CPF a ser validado (formato "XXX.XXX.XXX-XX", seguindo norma oficial do CPF).
 * @throw std::invalid_argument Se o CPF for inv�lido.
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
        throw invalid_argument("Perfil inv�lido. Deve ser 'conservador', 'moderado' ou 'agressivo'.");
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

