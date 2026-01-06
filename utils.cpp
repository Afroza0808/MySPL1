#include "utils.h"
#include<cctype>
namespace utils{
    std::string sanitize_text(const std::string &s){
        std::string out;
        out.reserve(s.size());
        for(char ch:s){
            if(std::isalpha(static_cast<unsigned char>(ch))){
                char up=static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
                out.push_back(up);
            }
        }
        return out;
    }
    int charToIndex(char c){
        char up=static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        if(up>='A'&& up<='Z'){
            return up -'A';
        }
        return -1;
    }
    char indexToChar(int i){
        i=mod(i,26);
        return static_cast<char>('A'+i);
    }
    int mod(int a, int m) {
    int r = a % m;
    if (r < 0) r += m;
    return r;
   }

   int gcd(int a,int b){
      return (b==0) ? a: gcd(b,a%b);
   }

   int modInverse(int a,int m){
       a=mod(a,m);
       for(int x=1;x<m;x++){
        if(mod(a*x,m)==1){
           return x;
        }
       }
       return -1;
   }
}