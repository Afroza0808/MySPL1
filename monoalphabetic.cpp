#include "monoalphabetic.h"
#include "utils.h"
#include<vector>

MonoalphabeticCipher::MonoalphabeticCipher(const std::string &key){
    std::string clean=utils::sanitize_text(key);
    forward_.fill('?');
    backward_.fill('?');

    if(clean.size()!=26){
        return;
    }
   
    for(int i=0;i<26;i++){
        char c=clean[i];
        int idx=utils::charToIndex(c);
        if(idx>=0){
            forward_[i]=c;
            backward_[idx]=utils::indexToChar(i);
        }
    }
}
bool MonoalphabeticCipher::validate() const{
    std::vector<bool>seen(26,false);

    for(int i=0;i<26;i++){
        if(forward_[i]<'A'||forward_[i]>'Z'){
            return false;
        }
       int idx=utils::charToIndex(forward_[i]);
       if(seen[idx]){
        return false;
       }
       seen[idx]=true;
    }
    return true;
}
std::string MonoalphabeticCipher::getKey() const {
    std::string k;
    for (char c : forward_) k.push_back(c);
    return k;
}
std::string MonoalphabeticCipher::encrypt(const std::string &plaintext){
    std::string clean=utils::sanitize_text(plaintext);
    std::string out;
    out.reserve(clean.size());

    for(char p:clean){
        int idx=utils::charToIndex(p);
        out.push_back(forward_[idx]);
    }
    return out;
}
std::string MonoalphabeticCipher::decrypt(const std::string &ciphertext){
    std::string clean=utils::sanitize_text(ciphertext);
    std::string out;
    out.reserve(clean.size());

    for(char c:clean){
        int idx=utils::charToIndex(c);
        out.push_back(backward_[idx]);
    }
    return out;
}
