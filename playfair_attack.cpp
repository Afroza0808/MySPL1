#include "playfair_attack.h"
#include "analysis_utils.h"
#include <iostream>
#include <map>

namespace playfair_attack {

void analyze_digraphs(const std::string &ciphertext){

    std::string clean = analysis::clean(ciphertext);

    std::map<std::string,int> digraph_freq;

    // create digraphs
    for(size_t i=0;i<clean.size()-1;i+=2){

        std::string pair="";
        pair.push_back(clean[i]);
        pair.push_back(clean[i+1]);

        digraph_freq[pair]++;
    }

    std::cout<<"\n[Playfair Cryptanalysis - Digraph Frequency]\n";

    for(auto &p:digraph_freq){
        std::cout<<p.first<<" -> "<<p.second<<"\n";
    }

    std::cout<<"\nCommon English digraphs might correspond to:\n";
    std::cout<<"TH HE IN ER AN RE ON AT EN ND\n";
}

}