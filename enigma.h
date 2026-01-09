#pragma once
#include "cipher_base.h"
#include <vector>
#include <string>

class EnigmaCipher : public CipherBase {
public:
    EnigmaCipher(const std::vector<std::string> &rotors,
                 const std::string &reflector,
                 const std::string &positions);

    std::string encrypt(const std::string &plaintext) override;
    std::string decrypt(const std::string &ciphertext) override;
    bool validate() const override;

private:
    std::vector<std::string> rotors_;
    std::vector<std::string> inv_rotors_;
    std::string reflector_;
    std::vector<int> pos_;

    void stepRotors();
    char processChar(char c);
};
