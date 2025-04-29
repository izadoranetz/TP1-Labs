#ifndef PROFILE_HPP_INCLUDED
#define PROFILE_HPP_INCLUDED
#include <stdexcept>
#include <string>

using namespace std;

class Profile{
    private:
    enum profile_options { conservador, moderado, agressivo  };
    profile_options profile;
    bool checkProfile(string profile);
    string identifyProfile(profile_options profile) const; 

    public:
        void setProfile(string profile);
        string getProfile() const; 
};


/**
 * @brief Retorna o perfil do investimento.
 * @return std::string Perfil no formato especificado.
 */

 inline string Profile::getProfile() const { 
    return identifyProfile(profile);
}

#endif // DOMINIOS_HPP_INCLUDED