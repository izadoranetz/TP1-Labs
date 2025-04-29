#include <iostream>
#include "Cpf.hpp"
#include "Profile.hpp"

using namespace std;

int main(){
    cout << "Teste de Classes para o Tralho" << endl;

    cout << endl;
    cout << "Definindo um CPF válido" << endl;

    Cpf cpf;
    // cpf valido
    try {
        cpf.setCpf("12345678909");
        cout << "CPF definido: " << cpf.getCpf() << endl;
    } catch (invalid_argument &exp) {
        cout << "Excecao (invalid_argument): " << exp.what() << endl;
    } catch (length_error &exp) {
        cout << "Excecao (length_error): " << exp.what() << endl;
    } catch (...) {
        cout << "Excecao desconhecida" << endl;
    }

    cout << endl;
    cout << "Definindo um CPF inválido" << endl;

    // cpf invalido
    try {
        cpf.setCpf("12345678900");
        cout << "CPF definido: " << cpf.getCpf() << endl;
    } catch (invalid_argument &exp) {
        cout << "Excecao (invalid_argument): " << exp.what() << endl;
    } catch (length_error &exp) {
        cout << "Excecao (length_error): " << exp.what() << endl;
    } catch (...) {
        cout << "Excecao desconhecida" << endl;
    }

    cout << endl;
    cout << "Definindo um Perfil válido" << endl;

    Profile perfil;
    // perfil valido
    try {
        perfil.setProfile("conservador");
        cout << "Perfil definido: " << perfil.getProfile() << endl;
    } catch (invalid_argument &exp) {
        cout << "Excecao (invalid_argument): " << exp.what() << endl;
    } catch (...) {
        cout << "Excecao desconhecida" << endl;
    }

    cout << endl;
    cout << "Definindo um Perfil inválido" << endl;
    // perfil invalido
    try {
        perfil.setProfile("ueigfisdfg");
        cout << "Perfil definido: " << perfil.getProfile() << endl;
    } catch (invalid_argument &exp) {
        cout << "Excecao (invalid_argument): " << exp.what() << endl;
    } catch (length_error &exp) {
        cout << "Excecao (length_error): " << exp.what() << endl;
    } catch (...) {
        cout << "Excecao desconhecida" << endl;
    }

    cout << endl;
    return 0;
}