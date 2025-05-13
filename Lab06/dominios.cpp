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
        throw invalid_argument("CPF não possui 11 dígitos.");
    }

    // verifica se todos caracteres sao iguais
    if (cpf.find_first_not_of(cpf[0]) == std::string::npos) {
        throw invalid_argument("CPF possui todos os digitos iguais.");
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
        throw invalid_argument("Primeiro dígito verificado do cpf é inválido.");
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
        throw invalid_argument("Segundo dígito verificado do cpf é inválido.");
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
 * @brief Verifica se o perfil do investimento é válido a partir da relação de perfis possíveis.
 * @param profile Perfil a ser validado ( Conservador, Moderado, Agressivo ).
 * @return true Se o perfil for válido.
 * @return false Se o perfil for inválido.
 */

 bool Profile::checkProfile(string profile) {
    static const regex pattern("^(conservador|moderado|agressivo)$");
    return regex_match(profile, pattern);
}

/**
 * @brief Define o perfil do investimento após a validação do perfil informado.
 * @param profile Perfil a ser definido.
 * @throw std::invalid_argument Se o perfil for inválido.
 */

 void Profile::setProfile(string profile) {
  if(!checkProfile(profile)) {
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

/** 
 * @brief Retorna a string correspondente ao perfil do investimento selecionado.
 * @param profile Perfil a ser identificado ( Conservador, Moderado, Agressivo ).
 * @return string Nome do perfil correspondente.
*/

string Profile::identifyProfile(Profile::profile_options profile) const {
    switch (profile) {
        case conservador: return "conservador";
        case moderado: return "moderado";
        case agressivo: return "agressivo";
        default: return "perfil desconhecido";
    }
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

bool Name::checkName(string name) {
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