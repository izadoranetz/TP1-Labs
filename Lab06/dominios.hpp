#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED
#include <stdexcept>
#include <string>

using namespace std;

class Dominio {
    private:
        string valor;
        void validar(string);
    public:
        void setValor(string);
        string getValor();
};

inline string Dominio::getValor() {
    return valor;
};

// CPF
class Cpf{
    private:
    string cpf;
    bool checkCpf(string cpf);

    public:
        void setCpf(string cpf);
        string getCpf() const;
};

/**
 * @brief Retorna o CPF armazenado.
 * @return std::string CPF no formato "XXX.XXX.XXX-XX".
 */

 inline string Cpf::getCpf() const { 
    return cpf;
 };

 // Profile
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

class Code{    
    private:
    string code;
    bool checkCode(string code);

    public:
        void setCode(string code);
        string getCode() const;
};

/**
* @brief Retorna o valor do código.
* @return std::string Código no formato "XXXXX".
*/

inline string Code::getCode() const { 
    return code; 
 }


class Name{
    private:
        string name;
        bool checkName(string name);

    public:
        void setName(string name);
        string getName() const;
};

/**
 * @brief Retorna o nome armazenado.
 * @return std::string Nome no formato válido.
 */

inline string Name::getName() const { 
    return name; 
}

#endif // DOMINIOS_HPP_INCLUDED