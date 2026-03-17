#include "vigenere_attack.h"
#include "analysis_utils.h"
#include <iostream>

namespace vigenere_attack {

void guess_key_length(const std::string &ciphertext) {
    std::string clean = analysis::clean(ciphertext);

    std::cout << "\n[Vigenere Key Length Guess]\n";

    for (int m = 1; m <= 12; m++) {
        double avg = 0;

        for (int i = 0; i < m; i++) {
            std::string group;
            for (int j = i; j < clean.size(); j += m)
                group.push_back(clean[j]);

            avg += analysis::index_of_coincidence(group);
        }

        avg /= m;

        std::cout << "Length " << m << " -> IOC = " << avg << "\n";
    }
}

}
