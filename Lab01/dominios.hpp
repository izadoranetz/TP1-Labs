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
    string cpf;
    bool validar(const string& cpf);
public:
    void setCpf(const string& cpf);
    string getCpf() const;
};

class Profile{
    private:
    enum profile_options { conservador, moderado, agressivo  };
    profile_options profile;
    public:
        void setProfile(string profile);
        string getProfile();
};


#endif // DOMINIOS_HPP_INCLUDED
