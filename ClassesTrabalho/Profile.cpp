#include "Profile.hpp"
#include <array>
#include <regex>

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