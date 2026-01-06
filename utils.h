#pragma once
#include<string>
#include<vector>
namespace utils{
    std:: string sanitize_text(const std::string &s);
    int charToIndex(char c);
    char indexToChar(int i);
    int mod(int a,int m);

    int gcd(int a,int b);
    int modInverse(int a,int m);
}