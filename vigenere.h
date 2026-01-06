#pragma once
#include"cipher_base.h"
#include<string>

class VigenereCipher: public CipherBase{
    public:
    explicit VigenereCipher(const std::string &key);

    std::string encrypt(const std::string &plaintext) override;
    std::string decrypt(const std::string &ciphertext) override;
    bool validate() const override;

    std:: string getKey() const;

    private:
    std:: string key_;
};