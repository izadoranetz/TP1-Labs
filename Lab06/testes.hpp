#ifndef TESTES_HPP_INCLUDED
#define TESTES_HPP_INCLUDED
#include <stdexcept>
#include <string>

#include "dominios.hpp"
#include "entidades.hpp"

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


class TUProfile {
    private:
        const string VALID_VALUE = "conservador"; // Perfil válido
        const string INVALID_VALUE = "agil"; // Perfil inválido (não reconhecido)
        Profile *profile;
        int state;
        void setUp();
        void tearDown();
        void testValidScenario();
        void testInvalidScenario();
    public:
        const static int SUCCESS = 0;
        const static int FAILURE = -1;
        int run();
};

class TUCpf {
    private:
        const string VALID_VALUE = "12345678909"; // CPF válido
        const string INVALID_VALUE = "11111111111"; // CPF inválido (todos os dígitos iguais)
        const string INVALID_VALUE2 = "12345678900"; // CPF inválido (dígitos verificadores incorretos)
        const string INVALID_VALUE3 = "1234567890";  // CPF inválido (menos de 11 dígitos)
        const string INVALID_VALUE4 = "1234567890a"; // CPF inválido (contém letras)
        Cpf *cpf;
        int state;
        void setUp();
        void tearDown();
        void testValidScenario();
        void testInvalidScenario();
    public:
        const static int SUCCESS = 0;
        const static int FAILURE = -1;
        int run();
};

class TUWallet {
    private:
        const string VALID_CODE = "12345"; // Código válido
        const string INVALID_CODE = "1234a"; // Código inválido (contém letras)
        const string INVALID_CODE2 = "123456"; // Código inválido (mais de 5 dígitos)
        const string VALID_NAME = "Wallet1"; // Nome válido
        const string INVALID_NAME = "Wallet 1"; // Nome inválido (contém espaço)
        const string INVALID_NAME2 = "Wallet12345678901234567890"; // Nome inválido (mais de 20 caracteres)
        const string VALID_PROFILE = "conservador"; // Perfil válido
        const string INVALID_PROFILE = "agil"; // Perfil inválido (não reconhecido)
        Wallet *wallet;
        int state;
        void setUp();
        void tearDown();
        void testValidScenario();
        void testInvalidScenario();
    public:
        const static int SUCCESS = 0;
        const static int FAILURE = -1;
        int run();
};

#endif // DOMINIOS_HPP_INCLUDED