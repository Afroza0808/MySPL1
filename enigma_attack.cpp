#include "enigma_attack.h"
#include "enigma.h"
#include <iostream>

namespace enigma_attack {

std::string pos_to_string(int a,int b,int c){
    std::string s;
    s.push_back('A'+a);
    s.push_back('A'+b);
    s.push_back('A'+c);
    return s;
}

void brute_force_position(
    const std::string &ciphertext,
    const std::string &known_plain,
    const std::vector<std::string> &rotors,
    const std::string &reflector
){

    std::cout<<"[Enigma Cryptanalysis]\n";

    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            for(int k=0;k<26;k++){

                std::string pos = pos_to_string(i,j,k);

                EnigmaCipher test(rotors,reflector,pos);

                std::string dec=test.decrypt(ciphertext);

                if(dec.substr(0,known_plain.size())==known_plain){

                    std::cout<<"Found Rotor Position: "<<pos<<"\n";
                    std::cout<<"Recovered Plaintext: "<<dec<<"\n";
                    return;
                }
            }
        }
    }

    std::cout<<"No matching position found\n";
}

}