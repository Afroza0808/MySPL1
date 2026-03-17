#include "analysis_utils.h"
#include <cctype>
#include <cmath>

namespace analysis {

std::string clean(const std::string &text) {
    std::string out;
    for (char c : text)
        if (isalpha(c))
            out.push_back(toupper(c));
    return out;
}

std::vector<int> frequency_count(const std::string &text) {
    std::vector<int> f(26, 0);
    for (char c : text)
        f[c - 'A']++;
    return f;
}

double index_of_coincidence(const std::string &text) {
    auto f = frequency_count(text);
    double n = text.size();

    double sum = 0;
    for (int x : f)
        sum += x * (x - 1);

    return sum / (n * (n - 1));
}

static const double EN_FREQ[26] = {
    8.2,1.5,2.8,4.3,12.7,2.2,2.0,6.1,7.0,0.15,0.77,4.0,2.4,
    6.7,7.5,1.9,0.095,6.0,6.3,9.1,2.8,1.0,2.4,0.15,2.0,0.074
};

double chi_squared(const std::vector<int> &freq, int n) {
    double chi = 0;

    for (int i = 0; i < 26; i++) {
        double expected = EN_FREQ[i] * n / 100.0;
        double diff = freq[i] - expected;
        chi += diff * diff / expected;
    }
    return chi;
}

}
