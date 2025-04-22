#ifndef DOMINIOS_HPP_INCLUDE
#define DOMINIOS_HPP_INCLUDE

class Codigo {
    private:
        string valor;
        virtual bool validar(string) = 0;
    public:
        bool setValor(string);
        string getValor() const;
};

inline string Codigo::getValor() const {
    return valor;
}


#endif DOMINIOS_HPP_INCLUDE