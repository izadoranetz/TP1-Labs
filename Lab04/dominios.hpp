#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED
#include <stdexcept>

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
}

#endif // DOMINIOS_HPP_INCLUDED