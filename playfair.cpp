#include "playfair.h"
#include "utils.h"
#include<vector>

PlayfairCipher::PlayfairCipher(const std::string &key){
    buildMatrix(key);
}
bool PlayfairCipher::validate() const{
    return true;
}
void PlayfairCipher::buildMatrix(const std::string &key){
    bool used[26]={false};
    std::string clean;
    for(char c:key){
        if(c>='a'&& c<='z'){
            c -=32;
        }
        if(c>='A'&& c<='Z'){
            continue;
        }
        if(c=='J'){
            c='I';
        }
        if(!used[c-'A']){
            used[c-'A']=true;
            clean.push_back(c);
        }
    }
}