#include "monoalphabetic_attack.h"
#include "analysis_utils.h"
#include <iostream>
#include <algorithm>

namespace monoalphabetic_attack {

void break_mono(const std::string &ciphertext) {
    std::string cleanText = analysis::clean(ciphertext);
    auto freq = analysis::frequency_count(cleanText);

    // Rank letters by frequency
    std::vector<std::pair<int,char>> freqPair;
    for(int i=0;i<26;i++)
        freqPair.push_back({freq[i], 'A'+i});

    std::sort(freqPair.begin(), freqPair.end(), [](auto &a, auto &b){
        return a.first > b.first;
    });

    // English letters by frequency
    std::string eng_freq = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

    std::string mapping(26,' ');

    for(int i=0;i<26;i++)
        mapping[freqPair[i].second - 'A'] = eng_freq[i];

    std::string guessed_plain;
    for(char c: cleanText)
        guessed_plain.push_back(mapping[c-'A']);

    std::cout << "\n[Monoalphabetic Frequency Analysis Attack]\n";
    std::cout << "Guessed Plaintext: " << guessed_plain << "\n";
}

}