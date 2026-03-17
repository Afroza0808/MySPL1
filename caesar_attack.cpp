#include "caesar_attack.h"
#include "analysis_utils.h"
#include "caesar.h"
#include "utils.h"

#include <iostream>
#include <limits>

namespace caesar_attack {

void break_caesar(const std::string &ciphertext) {

    std::string cleanText = analysis::clean(ciphertext);

    double best_score = std::numeric_limits<double>::max();
    int best_key = 0;
    std::string best_plain;

    for(int k=0;k<26;k++) {

        CaesarCipher cipher(k);

        std::string pt = cipher.decrypt(cleanText);

        auto freq = analysis::frequency_count(pt);

        double score = analysis::chi_squared(freq, pt.size());

        if(score < best_score){
            best_score = score;
            best_key = k;
            best_plain = pt;
        }
    }

    std::cout << "\n====== Caesar Attack Result ======\n";
    std::cout << "Key: " << best_key << "\n";
    std::cout << "Plaintext: " << best_plain << "\n";
}

}
