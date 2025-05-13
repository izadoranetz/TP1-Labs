#include "dominios.hpp"
#include <array>
#include <regex>

using namespace std;

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

/**
 * @brief Verifica CPF informado, conforme regras oficiais de cálculo do primeiro e segundo dígitos verificadores.
 * @param cpf CPF informado que será validado.
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

bool Code::checkCode(string code) {
    static const regex code_regex("^[0-9]{5}$");
    return regex_match(code, code_regex);
}

/**
* @brief Define o valor do código.
* @param code Código a ser validado (formato "XXXXX", onde X é dígito).
* @throw std::invalid_argument Se o código for inválido.
*/

void Code::setCode(string code) {
    if(!checkCode(code)) {
        throw invalid_argument("Código inválido. Deve conter 5 dígitos.");
    }
    this->code = code; 
}

bool checkName(string name) {
    static const regex name_regex("^[A-Za-z0-9](?:[A-Za-z0-9]| (?=\\S)){0,19}$");
    return regex_match(name, regex(name_regex));
}

/**
 * @brief Define o nome após validação.
 * @param name Nome a ser validado (1-20 caracteres alfanuméricos, sem espaços duplos).
 * @throw std::invalid_argument Se o nome for inválido.
 */

void Name::setName(string name) { 
    if(!checkName(name)){
        throw invalid_argument("Nome inválido. Deve conter entre 1 e 20 caracteres alfanuméricos, sem espaços duplos.");
    }
    this->name = name;
}