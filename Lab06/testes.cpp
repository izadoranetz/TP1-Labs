#include "testes.hpp"

void TUDominio::setUp() {
    dominio = new Dominio();
    estado = SUCESSO;
}

void TUDominio::tearDown() {
    delete dominio;
}

void TUDominio::testarCenarioValorValido(){
    try {
        dominio->setValor(VALOR_VALIDO); 
        if (dominio->getValor() != VALOR_VALIDO)
        estado = FALHA;
    }
    catch (invalid_argument &exception){
        estado = FALHA;
    }
}

void TUDominio::testarCenarioValorInvalido(){
    try{
        dominio->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &exception){
        if(dominio->getValor() == VALOR_INVALIDO)
        estado = FALHA;
    }
}

int TUDominio::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}

void TUProfile::setUp() {
    profile = new Profile();
    state = SUCCESS;	
}

void TUProfile::tearDown() {
    delete profile;
}

void TUProfile::testValidScenario(){
    try {
        profile->setProfile(VALID_VALUE); 
        if (profile->getProfile() != VALID_VALUE) {
            state = FAILURE;
        }
    }
    catch (invalid_argument &exception){
        state = FAILURE;
    }
}

void TUProfile::testInvalidScenario(){
    try{
        profile->setProfile(INVALID_VALUE);
        state = FAILURE;
    }
    catch(invalid_argument &exception){
        if(profile->getProfile() == INVALID_VALUE)
        state = FAILURE;
    }
}

int TUProfile::run(){
    setUp();
    testValidScenario();
    testInvalidScenario();
    tearDown();
    return state;
}

void TUCpf::setUp() {
    cpf = new Cpf();
    state = SUCCESS;	
}

void TUCpf::tearDown() {
    delete cpf;
}
void TUCpf::testValidScenario(){
    try {
        cpf->setCpf(VALID_VALUE); 
        if (cpf->getCpf() != VALID_VALUE) {
            state = FAILURE;
        }
    }
    catch (invalid_argument &exception){
        state = FAILURE;
    }
}
void TUCpf::testInvalidScenario(){
    try{
        cpf->setCpf(INVALID_VALUE);
        state = FAILURE;
    }
    catch(invalid_argument &exception){
        if(cpf->getCpf() == INVALID_VALUE)
        state = FAILURE;
    }
    try{
        cpf->setCpf(INVALID_VALUE2);
        state = FAILURE;
    }
    catch(invalid_argument &exception){
        if(cpf->getCpf() == INVALID_VALUE2)
        state = FAILURE;
    }
    try{
        cpf->setCpf(INVALID_VALUE3);
        state = FAILURE;
    }
    catch(invalid_argument &exception){
        if(cpf->getCpf() == INVALID_VALUE3)
        state = FAILURE;
    }
    try{
        cpf->setCpf(INVALID_VALUE4);
        state = FAILURE;
    }
    catch(invalid_argument &exception){
        if(cpf->getCpf() == INVALID_VALUE4)
        state = FAILURE;
    }
}

int TUCpf::run(){
    setUp();
    testValidScenario();
    testInvalidScenario();
    tearDown();
    return state;
}