#include"caesar.h"
#include"utils.h"
#include<sstream>
CaesarCipher:: CaesarCipher(int shift){
    setShift(shift);
}
void CaesarCipher::setShift(int s){
    shift_=utils::mod(s,26);
}
int CaesarCipher::getShift() const{
    return shift_;
}
bool CaesarCipher::validate() const{
    return(shift_>=0&& shift_<26);
}

std::string CaesarCipher::encrypt(const std::string &plaintext){
    std::string clean=utils::sanitize_text(plaintext);
    std::string out;
    out.reserve(clean.size());
    for(char c:clean){
        int idx=utils::charToIndex(c);
        if(idx>=0){
            int e=utils::mod(idx+shift_,26);
            out.push_back(utils::indexToChar(e));
        }
    }
    return out;
}

std::string CaesarCipher::decrypt(const std::string &ciphertext) {
     std::string clean=utils::sanitize_text(ciphertext);
    std::string out;
    out.reserve(clean.size());
    for(char c:clean){
        int idx=utils::charToIndex(c);
        if(idx>=0){
            int d=utils::mod(idx-shift_,26);
            out.push_back(utils::indexToChar(d));
        }
    }
    return out;
}