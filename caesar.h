#pragma once
#include"cipher_base.h"
#include<string>
class CaesarCipher: public CipherBase{
    public:
    explicit CaesarCipher(int shift=0);
    std::string encrypt(const std::string &plaintext) override;
    std::string decrypt(const std::string &ciphertext) override;
    bool validate() const override;

    void setShift(int s);
    int getShift() const;

    private:
    int shift_;
};