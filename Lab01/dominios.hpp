#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>

using namespace std;

class CodigoCliente {
    private:
        static const int LIMITE = 5;
        static const int DEFAULT = 0;
        int valor;
        bool validar(int);
    public:
        bool setValor(int);
        int getValor();

};

inline int CodigoCliente::getValor(){
    return valor;
};

class Cpf {
private:
    std::string cpf; //usa-se string porque o cpf pode iniciar com zeros
    bool validar(const std::string& cpf);
public:
    bool setCpf(const std::string& cpf);
    std::string getCpf() const;
};

#endif // DOMINIOS_HPP_INCLUDED
