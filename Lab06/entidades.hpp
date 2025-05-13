#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

#include "dominios.hpp"

class Wallet{
    private:
        Code code;
        Name name;
        Profile profile;
    public:
        void setCode(Code);
        Code getCode();
        void setName(Name);
        Name getName();
        void setProfile(Profile);
        Profile getProfile();
        
};
inline void Wallet::setCode(Code code){
    this->code = code;
}
inline Code Wallet::getCode(){
    return code;
}
inline void Wallet::setName(Name name){
    this->name = name;
}
inline Name Wallet::getName(){
    return name;
}
inline void Wallet::setProfile(Profile profile){
    this->profile = profile;
}
inline Profile Wallet::getProfile(){
    return profile;
}

#endif // ENTIDADES_HPP_INCLUDED