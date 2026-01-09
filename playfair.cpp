#include "playfair.h"
#include "utils.h"
#include <vector>

PlayfairCipher::PlayfairCipher(const std::string &key) {
    buildMatrix(key);
}

bool PlayfairCipher::validate() const {
    return true; 
}

void PlayfairCipher::buildMatrix(const std::string &key) {
    bool used[26] = {false};

    std::string clean;
    for (char c : key) {
        if (c >= 'a' && c <= 'z')
               {c -= 32;
                }
        if (c < 'A' || c > 'Z'){
             continue;
        }
        if (c == 'J'){
             c = 'I';
        }
        if (!used[c - 'A']) {
            used[c - 'A'] = true;
            clean.push_back(c);
        }
    }

    for (char c = 'A'; c <= 'Z'; ++c) {
        if (c == 'J'){
             continue;
            }
        if (!used[c - 'A']) {
            used[c - 'A'] = true;
            clean.push_back(c);
        }
    }

    int k = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matrix_[i][j] = clean[k];
            row_[clean[k] - 'A'] = i;
            col_[clean[k] - 'A'] = j;
            k++;
        }
    }
}

std::string PlayfairCipher::prepareText(const std::string &text, bool encryptMode) {
    std::string clean = utils::sanitize_text(text);
    std::string out;

    for (char &c : clean) {
        if (c == 'J') c = 'I';
    }

    for (size_t i = 0; i < clean.size(); i++) {
        out.push_back(clean[i]);
        if (i + 1 < clean.size() && clean[i] == clean[i + 1]) {
            out.push_back('X');
        }
    }

    if (out.size() % 2 != 0)
        out.push_back('X');

    return out;
}

void PlayfairCipher::processPair(char &a, char &b, bool encryptMode) {
    int r1 = row_[a - 'A'], c1 = col_[a - 'A'];
    int r2 = row_[b - 'A'], c2 = col_[b - 'A'];

    int shift = encryptMode ? 1 : -1;

    if (r1 == r2) {
        a = matrix_[r1][utils::mod(c1 + shift, 5)];
        b = matrix_[r2][utils::mod(c2 + shift, 5)];
    }
    else if (c1 == c2) {
        a = matrix_[utils::mod(r1 + shift, 5)][c1];
        b = matrix_[utils::mod(r2 + shift, 5)][c2];
    }
    else {
        a = matrix_[r1][c2];
        b = matrix_[r2][c1];
    }
}

std::string PlayfairCipher::encrypt(const std::string &plaintext) {
    std::string prepared = prepareText(plaintext, true);
    std::string out;

    for (size_t i = 0; i < prepared.size(); i += 2) {
        char a = prepared[i];
        char b = prepared[i + 1];
        processPair(a, b, true);
        out.push_back(a);
        out.push_back(b);
    }
    return out;
}

std::string PlayfairCipher::decrypt(const std::string &ciphertext) {
    std::string clean = utils::sanitize_text(ciphertext);
    std::string out;

    for (size_t i = 0; i < clean.size(); i += 2) {
        char a = clean[i];
        char b = clean[i + 1];
        processPair(a, b, false);
        out.push_back(a);
        out.push_back(b);
    }
    return out;
}
