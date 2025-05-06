#ifndef TESTES_HPP_INCLUDED
#define TESTES_HPP_INCLUDED
#include <stdexcept>
#include <string>

#include "dominios.hpp"

using namespace std;

class TUDominio {
    private:
        const string VALOR_VALIDO = "20";
        const string VALOR_INVALIDO = "100";
        Dominio *dominio;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValorValido();
        void testarCenarioValorInvalido();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

#endif // DOMINIOS_HPP_INCLUDED