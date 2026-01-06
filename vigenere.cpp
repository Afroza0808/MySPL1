#include"vigenere.h"
#include "utils.h"
VigenereCipher:: VigenereCipher(const std::string &key){
    key_=utils::sanitize_text(key);
}
bool VigenereCipher::validate() const{
    return !key_.empty();
}
std::string VigenereCipher::getKey() const{
    return key_;
}
std::string VigenereCipher::encrypt(const std::string &plaintext){
    std::string clean=utils::sanitize_text(plaintext);
    std::string out;
    out.reserve(clean.size());

    int keyLen=static_cast<int>(key_.size());
    int j=0;
    for(char p:clean){
        int pIdx=utils::charToIndex(p);
        int kIdx=utils::charToIndex(key_[j%keyLen]);
        int cIdx=utils::mod(pIdx+kIdx,26);
        out.push_back(utils::indexToChar(cIdx));

        j++;
    }
    return out;

}
std::string VigenereCipher:: decrypt(const std::string &ciphertext){
    std::string clean=utils::sanitize_text(ciphertext);
    std::string out;
    out.reserve(clean.size());

    int keyLen=static_cast<int>(key_.size());
    int j=0;
    for(char c:clean){
        int cIdx=utils::charToIndex(c);
        int kIdx=utils::charToIndex(key_[j%keyLen]);
        int pIdx=utils::mod(cIdx-kIdx,26);
        out.push_back(utils::indexToChar(pIdx));

        j++;
    }
    return out;

}