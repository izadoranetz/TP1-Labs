#ifndef CPF_HPP_INCLUDED
#define CPF_HPP_INCLUDED
#include <stdexcept>
#include <string>

using namespace std;

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
}

#endif // DOMINIOS_HPP_INCLUDED