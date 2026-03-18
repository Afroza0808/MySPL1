#include "menu.h"
#include <iostream>

namespace menu {

void show_main_menu(){

    std::cout<<"\n==============================\n";
    std::cout<<" Classical Cryptography Lab\n";
    std::cout<<"==============================\n";

    std::cout<<"1. Encryption Demo\n";
    std::cout<<"2. Cryptanalysis Demo\n";
    std::cout<<"3. Exit\n";

    std::cout<<"Enter choice: ";
}

void encryption_menu(){

    std::cout<<"\n---- Encryption Algorithms ----\n";

    std::cout<<"1 Caesar Cipher\n";
    std::cout<<"2 Vigenere Cipher\n";
    std::cout<<"3 Monoalphabetic Cipher\n";
    std::cout<<"4 Hill Cipher\n";
    std::cout<<"5 Playfair Cipher\n";
    std::cout<<"6 Enigma Cipher\n";

}

void cryptanalysis_menu(){

    std::cout<<"\n---- Cryptanalysis ----\n";

    std::cout<<"1 Caesar Attack\n";
    std::cout<<"2 Vigenere Attack\n";
    std::cout<<"3 Monoalphabetic Attack\n";
    std::cout<<"4 Hill Known Plain Attack\n";
    std::cout<<"5 Playfair Digraph Analysis\n";
    std::cout<<"6 Enigma Brute Force\n";

}

}