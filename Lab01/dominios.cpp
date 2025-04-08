#include "dominios.hpp"
#include <algorithm>

bool CodigoCliente::validar(int valor){
if(valor>LIMITE)
    return false;
return true;
}

bool CodigoCliente::setValor(int valor){
if (!validar(valor))
    return false;
this-> valor = valor;
return true;
}


bool Cpf::validar(const std::string& cpf){
// verifica tamanho de 11 digitos
if(cpf.length() != 11 ||
   !std::all_of(cpf.begin(), cpf.end(), ::isdigit)) {
    return false;
}

// TODO: Implementar validação dos dígitos verificadores
// (Algoritmo oficial de validação de CPF)
// exemplo em javascript:
// function validarCPF(cpf) {
//	cpf = cpf.replace(/[^\d]+/g,'');
//	if(cpf == '') return false;
	// Elimina CPFs invalidos conhecidos
//	if (cpf.length != 11 ||
//		cpf == "00000000000" ||
//		cpf == "11111111111" ||
//		cpf == "22222222222" ||
//		cpf == "33333333333" ||
//		cpf == "44444444444" ||
//		cpf == "55555555555" ||
//		cpf == "66666666666" ||
//		cpf == "77777777777" ||
//		cpf == "88888888888" ||
//		cpf == "99999999999")
//			return false;
	// Valida 1o digito
//	add = 0;
//	for (i=0; i < 9; i ++)
//		add += parseInt(cpf.charAt(i)) * (10 - i);
//		rev = 11 - (add % 11);
//		if (rev == 10 || rev == 11)
//			rev = 0;
//		if (rev != parseInt(cpf.charAt(9)))
//			return false;
	// Valida 2o digito
//	add = 0;
//	for (i = 0; i < 10; i ++)
//		add += parseInt(cpf.charAt(i)) * (11 - i);
//	rev = 11 - (add % 11);
//	if (rev == 10 || rev == 11)
//		rev = 0;
//	if (rev != parseInt(cpf.charAt(10)))
//		return false;
//	return true;
//}

return true;

}

bool Cpf::setCpf(const std::string& cpf){
if (!validar(cpf))
    return false;
this->cpf = cpf;
return true;
}

std::string Cpf::getCpf() const {
return cpf;
}
