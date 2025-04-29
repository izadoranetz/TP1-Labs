#include "Cpf.hpp"
#include <array>
#include <regex>

// CPF

/**
 * @brief Verifica CPF informado, conforme regras oficiais.
 * @param cpf CPF a ser validado.
 * @throw std::invalid_argument Se o CPF for inválido.
 */

 bool Cpf::checkCpf(string cpf){
    
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
    array<int, 11> digits;
    for (size_t i = 0; i < cpf.length(); i++) {
        digits[i] = cpf[i] - '0';
    }

    /* verifica o primeiro digito
    * multiplica os 9 primeiros digitos, da direita para esquerda, por numeros crescentes a partir de 2
    */
    int weight = 10;
    int sum = 0;
    for (size_t i = 0; i < 9; i++){
        sum += (digits[i]*weight);
        weight--;
    }

    /* pega o resultado e divide por 11
    * se o resto da divisao for menor que 2, o digito eh igual a zero
    * se o resto da divisao for maior ou igual a 2, entao o digito eh igual a 11 - resto
    */
    int rem = sum % 11;
    int first_digit;
    if(rem < 2){
        first_digit = 0;
    } else {
        first_digit = 11 - rem;
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
        second_digit = 0;
    } else {
        second_digit = 11 - rem;
    }

    if(second_digit != digits[10]){
        return false;
    }

return true;

}

// adaptar o checkCpf para retornar void, usando try catch


/**
 * @brief Define o CPF após validação.
 * @param cpf CPF a ser validado.
 * @throw std::invalid_argument Se o CPF for inválido.
 */

 void Cpf::setCpf(string cpf) {
    if(!checkCpf(cpf)) {
        throw invalid_argument("Cpf invalido");
    }
    this->cpf = cpf;
}