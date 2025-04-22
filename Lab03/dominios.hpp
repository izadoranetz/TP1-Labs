#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

class Codigo {
    private:
        int valor;
        virtual bool validar(int) = 0;
    public:
        bool setValor(int);
        int getValor() const;
};

inline int Codigo::getValor() const {
    return valor;
}

class CodigoCliente:public Codigo {
    private:
        bool validar(int) override;
};

#endif // DOMINIOS_HPP_INCLUDED