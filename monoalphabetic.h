#pragma once
#include "cipher_base.h"
#include<array>
#include<string>

class MonoalphabeticCipher : public CipherBase{
    public:
    explicit MonoalphabeticCipher(const std::string &key);
     std::string encrypt(const std::string &plaintext) override;
    std::string decrypt(const std::string &ciphertext) override;
    bool validate() const override;

    std::string getKey() const;

    private:
    std::array<char,26>forward_;
    std::array<char,26>backward_;
};