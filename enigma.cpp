#include "enigma.h"
#include "utils.h"

EnigmaCipher::EnigmaCipher(const std::vector<std::string> &rotors,
                           const std::string &reflector,
                           const std::string &positions)
    : rotors_(rotors), reflector_(reflector) {

    for (auto &r : rotors_) {
        std::string inv(26, 'A');
        for (int i = 0; i < 26; i++) {
            inv[r[i] - 'A'] = 'A' + i;
        }
        inv_rotors_.push_back(inv);
    }

    for (char c : positions)
        pos_.push_back(c - 'A');
}

bool EnigmaCipher::validate() const {
    return rotors_.size() == pos_.size();
}

void EnigmaCipher::stepRotors() {
    pos_[0] = (pos_[0] + 1) % 26;

    for (size_t i = 0; i < pos_.size() - 1; i++) {
        if (pos_[i] == 0)
            pos_[i + 1] = (pos_[i + 1] + 1) % 26;
    }
}

char EnigmaCipher::processChar(char c) {
    int x = c - 'A';

    
    for (size_t i = 0; i < rotors_.size(); i++) {
        x = (rotors_[i][(x + pos_[i]) % 26] - 'A' - pos_[i] + 26) % 26;
    }

    x = reflector_[x] - 'A';

    for (int i = rotors_.size() - 1; i >= 0; i--) {
        x = (inv_rotors_[i][(x + pos_[i]) % 26] - 'A' - pos_[i] + 26) % 26;
    }

    return 'A' + x;
}

std::string EnigmaCipher::encrypt(const std::string &plaintext) {
    std::string clean = utils::sanitize_text(plaintext);
    std::string out;

    for (char c : clean) {
        stepRotors();
        out.push_back(processChar(c));
    }
    return out;
}

std::string EnigmaCipher::decrypt(const std::string &ciphertext) {
    return encrypt(ciphertext); 
}
