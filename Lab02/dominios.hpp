#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

class Codigo {
    private:
        static const int LIMITE = 25;
        int valor;
        bool validar(int);
    public:
        bool setValor(int);
        int getValor();
};

inline int Codigo::getValor(){
    return valor;
}

class Prioridade {
    private:
        static const int INVALIDO = 0;
        int valor;
        bool validar(int);
    public:
        bool setValor(int);
        int getValor();
};

inline int Prioridade::getValor() {
    return valor;
}

#endif // DOMINIOS_HPP_INCLUDED
