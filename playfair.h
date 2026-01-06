#pragma once
#include"cipher_base.h"
#include <vector>
#include <string>

class PlayfairCipher: public CipherBase{
    public:
    explicit PlayfairCipher(const std::string &key);

    std::string encrypt(const std::string &plaintext) override;
    std::string decrypt(const std::string &ciphertext) override;
    bool validate() const override;

    
    private:
      char matrix[5][5];
      int row_[26], col_[26];

      void buildMatrix(const std::string &key);
      std::string prepareText(const std::string &text, bool encryptMode);
      void processPair(char &a,char &b, bool encryptMode);

};