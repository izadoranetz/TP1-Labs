#include "tests.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

void testCpf(string value) {
    static int testNumber = 1;

    Cpf cpf;

    cout << "Teste #" << testNumber++ << ": ";

    try {
        cpf.setCpf(value);
        cout << "Sucesso - CPF valido: " << cpf.getCpf() << endl;
    } catch (const invalid_argument& e) {
        cout << "Falha - CPF invalido: " << value << " " << e.what() << endl;
    }

}
