#ifndef TESTES_HPP_INCLUDED
#define TESTES_HPP_INCLUDED
#include <stdexcept>
#include <string>

#include "Profile.hpp"
#include "Cpf.hpp"

using namespace std;

class TUProfile {
    private:
        const string VALID_VALUE = "conservador";
        const string INVALID_VALUE = "agil";
        Profile *profile;
        int state;
        void setUp();
        void tearDown();
        void testValidCenario();
        void testInvalidCenario();
    public:
        const static int SUCCESS = 0;
        const static int FAILURE = -1;
        int run();
};

class TUCpf {
    private:
        const string VALID_VALUE = "12345678909";
        const string INVALID_VALUE = "11111111111";
        const string INVALID_VALUE2 = "12345678900";
        const string INVALID_VALUE3 = "1234567890";
        const string INVALID_VALUE4 = "1234567890a";
        Cpf *cpf;
        int state;
        void setUp();
        void tearDown();
        void testValidCenario();
        void testInvalidCenario();
    public:
        const static int SUCCESS = 0;
        const static int FAILURE = -1;
        int run();
};


#endif 