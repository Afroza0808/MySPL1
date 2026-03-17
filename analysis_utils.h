#pragma once
#include <string>
#include <vector>

namespace analysis {

std::string clean(const std::string &text);

double index_of_coincidence(const std::string &text);

std::vector<int> frequency_count(const std::string &text);

double chi_squared(const std::vector<int> &freq, int n);

}
