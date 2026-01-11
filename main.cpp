#include <iostream>
#include <string>
#include "caesar.h"
#include "vigenere.h"
#include "monoalphabetic.h"
#include "hill.h"
#include "playfair.h"
#include "enigma.h"
#include "logger.h"

int main(){
    Logger logger("run.log");
    logger.info("Starting Classical Encryption and Decryption :::");

    std::string plaintext="Welcome.This is my first spl project of classical encryption and cryptanalysis.";
    logger.info(std::string("Original plaintext: ")+plaintext);


    CaesarCipher caesar(3);
    logger.info("Running Caesar Cipher: ");
    if(!caesar.validate()){
        logger.error("Caesar key invalid");
        return 1;
    }
    std::string caesar_ct=caesar.encrypt(plaintext);
    
    std::string caesar_pt=caesar.decrypt(caesar_ct);
    
    std::cout<<"==== Caesar Cipher ====\n";
    std::cout<<"Cipher(A-Z only) sanitized & encrypted:"<<caesar_ct<<"\n";
    std::cout<<"Decrypted (A-Z only):"<<caesar_pt<<"\n";
      logger.info("Finished Caesar implementation. ");


      VigenereCipher vigenere("LEMON");
      logger.info("Running Vigenere/Polyalphabetic Cipher (key= LEMON):  ");
    if(!vigenere.validate()){
        logger.error("Vigenere key invalid");
        return 1;
    
    }
    std::string vig_cipher=vigenere.encrypt(plaintext);
    std::string vig_plain =vigenere.decrypt(vig_cipher);

    std::cout<<"=====Vigenere Cipher====\n";
    std::cout << "Key        : " << vigenere.getKey() << "\n";
    std::cout<<"Ciphertext  : "<<vig_cipher<<"\n";
    std::cout<<"Decrypted  : "<<vig_plain<<"\n\n";
    logger.info("Finished vigenere implementation.");

    
    logger.info("Running Monoalphabetic Cipher :  ");
    std::string monokey="QWERTYUIOPASDFGHJKLZXCVBNM";
    MonoalphabeticCipher mono(monokey);

    if(!mono.validate()){
        logger.error("Mono alphabetic key invalid");
        return 1;
    
    }
    std::string mono_ct=mono.encrypt(plaintext);
    std::string mono_pt=mono.decrypt(mono_ct);

    std::cout<<"=====Monoalphabetic Cipher====\n";
    std::cout<<"key  :"<< mono.getKey() << "\n";
    std::cout<<"Ciphertext  : "<<mono_ct<<"\n";
    std::cout<<"Decrypted  : "<<mono_pt<<"\n\n";
    logger.info("Finished Monoalphabetic implementation.");


    logger.info("Running Hill Cipher :  ");
    std::vector<std::vector<int>>hillKey={
        {3,3},
        {2,5}
    };
    HillCipher hill(hillKey);

    
    std::string hill_ct=hill.encrypt(plaintext);
    std::string hill_pt=hill.decrypt(hill_ct);

    std::cout<<"=====Hill Cipher====\n";
    std::cout<<"Ciphertext  : "<<hill_ct<<"\n";
    std::cout<<"Decrypted  : "<<hill_pt<<"\n\n";
    logger.info("Finished Hill implementation.");

     std::cout<<"=====Playfair Cipher====\n";
    PlayfairCipher playfair("MONARCHY");

    std::string pf_ct = playfair.encrypt(plaintext);
    std::string pf_pt = playfair.decrypt(pf_ct);

    std::cout << "Ciphertext: " << pf_ct << "\n";
    std::cout << "Decrypted : " << pf_pt << "\n";
    logger.info("Finished Playfair implementation.");


    std::vector<std::string> rotors = {
        "EKMFLGDQVZNTOWYHXUSPAIBRCJ", 
        "AJDKSIRUXBLHWTMCQGZNPYFVOE", 
        "BDFHJLCPRTXVZNYEIWGAKMUSQO"  
    };

    std::string reflector = "YRUHQSLDPXNGOKMIEBFZCWVJAT"; 
    std::string positions = "AAA"; 

    EnigmaCipher enigma(rotors, reflector, positions);

    std::string ct = enigma.encrypt(plaintext);

    
    EnigmaCipher enigma2(rotors, reflector, positions);
    std::string pt = enigma2.decrypt(ct);

    std::cout << "Enigma Cipher:\n";
    std::cout << "Ciphertext: " << ct << "\n";
    std::cout << "Decrypted : " << pt << "\n";


    return 0;

}