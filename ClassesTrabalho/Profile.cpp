#include "Profile.hpp"
#include <array>
#include <regex>

// Profile

bool Profile::checkProfile(string profile) {
    static const regex pattern("^(conservador|moderado|agressivo)$");
    return regex_match(profile, pattern);
}

/**
 * @brief Define o perfil do investimento.
 * @param profile Perfil a ser validado ( Conservador, Moderado, Agressivo ).
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

// método identifyProfile para identificar o perfil correspondente do enum, para ser acionada pelo getProfile
string Profile::identifyProfile(Profile::profile_options profile) const {
    switch (profile) {
        case conservador: return "conservador";
        case moderado: return "moderado";
        case agressivo: return "agressivo";
        default: return "perfil desconhecido";
    }
}