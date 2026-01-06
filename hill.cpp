#include"hill.h"
#include "utils.h"

HillCipher::HillCipher(const std::vector<std::vector<int>>&key){
    k_=key;
    computeInverse();
}
bool HillCipher::validate() const{
    return k_.size()==2 && k_[0].size()==2 && k_[1].size()==2;
}

void HillCipher::computeInverse(){
    int a=k_[0][0];
    int b=k_[0][1];
    int c=k_[1][0];
    int d=k_[1][1];
    int det=utils::mod(a*d-b*c,26);
    int detInv=utils::modInverse(det,26);

    if(detInv==-1){
        kinv_.clear();
        return;
    }

    kinv_={
        {utils::mod(d*detInv,26),utils::mod(-b*detInv,26)},
        {utils::mod(-c*detInv,26),utils::mod(a*detInv,26)},
    };
}
std::string HillCipher::encrypt(const std::string &plaintext){
    std::string clean=utils::sanitize_text(plaintext);

    if(clean.size()%2!=0){
        clean.push_back('X');
    }
    std::string out;
    for(size_t i=0;i<clean.size();i+=2){
        int p1=utils::charToIndex(clean[i]);
        int p2=utils::charToIndex(clean[i+1]);

        int c1=utils::mod(k_[0][0]*p1 + k_[0][1]*p2,26);
        int c2=utils::mod(k_[1][0]*p1 + k_[1][1]*p2,26);

        out.push_back(utils::indexToChar(c1));
        out.push_back(utils::indexToChar(c2));
    }
    return out;
}
std::string HillCipher::decrypt(const std::string &ciphertext){
    std::string clean=utils::sanitize_text(ciphertext);
    std::string out;
    
    for(size_t i=0;i<clean.size();i+=2){
        int c1=utils::charToIndex(clean[i]);
        int c2=utils::charToIndex(clean[i+1]);

        int p1=utils::mod(k_[0][0]*c1 + k_[0][1]*c2,26);
        int p2=utils::mod(k_[1][0]*c1 + k_[1][1]*c2,26);

        out.push_back(utils::indexToChar(p1));
        out.push_back(utils::indexToChar(p2));
    }
    return out;
    
}
