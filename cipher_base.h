#pragma once
#include<string>
class CipherBase{
    public:
    virtual ~CipherBase()=default;

    virtual std::string encrypt(const std::string &plaintext)=0;

    virtual std::string decrypt(const std::string &ciphertext)=0;

    virtual bool validate() const{
        return true;
    }
};