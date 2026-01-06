#pragma once
#include"cipher_base.h"
#include<vector>

class HillCipher: public CipherBase{
    public:
    explicit HillCipher(const std::vector<std::vector<int>>&key);

    std::string encrypt(const std::string &plaintext) override;
    std::string decrypt(const std::string &ciphertext) override;
    bool validate() const override;

    
    private:
      std::vector<std::vector<int>>k_;
      std::vector<std::vector<int>>kinv_;

      void computeInverse();
};