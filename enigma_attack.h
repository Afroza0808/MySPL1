#pragma once
#include <string>
#include <vector>

namespace enigma_attack {

void brute_force_position(
    const std::string &ciphertext,
    const std::string &known_plain,
    const std::vector<std::string> &rotors,
    const std::string &reflector
);

}