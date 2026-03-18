#include <iostream>
#include <vector>
#include <string>

#include "menu.h"

#include "caesar.h"
#include "vigenere.h"
#include "monoalphabetic.h"
#include "hill.h"
#include "playfair.h"
#include "enigma.h"
#include "logger.h"

#include "caesar_attack.h"
#include "vigenere_attack.h"
#include "hill_attack.h"
#include "monoalphabetic_attack.h"
#include "playfair_attack.h"
#include "enigma_attack.h"


int main(){
    int choice;

    Logger logger("run.log");
    logger.info("Starting Classical Encryption and Decryption :::");

    std::string plaintext="Welcome.This is my first spl project of classical encryption and cryptanalysis.";
    logger.info(std::string("Original plaintext: ")+plaintext);

    
    std::vector<std::string> rotors = {
        "EKMFLGDQVZNTOWYHXUSPAIBRCJ", 
        "AJDKSIRUXBLHWTMCQGZNPYFVOE", 
        "BDFHJLCPRTXVZNYEIWGAKMUSQO"  
    };

    std::string reflector = "YRUHQSLDPXNGOKMIEBFZCWVJAT"; 
    std::string positions = "AAA"; 
     while(true){

        menu::show_main_menu();

        std::cin>>choice;

        if(choice==1){

            menu::encryption_menu();

            int c;
            std::cin>>c;

            if(c==1){
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
  }

   else if(c==2){
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
 }
    
 else if(c==3){
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
 }

  else if(c==4){
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
  }

  else if(c==5){
     std::cout<<"=====Playfair Cipher====\n";
    PlayfairCipher playfair("MONARCHY");

    std::string pf_ct = playfair.encrypt(plaintext);
    std::string pf_pt = playfair.decrypt(pf_ct);

    std::cout << "Ciphertext: " << pf_ct << "\n";
    std::cout << "Decrypted : " << pf_pt << "\n";
    logger.info("Finished Playfair implementation.");
   }

   
    
    else if(c==6){
    EnigmaCipher enigma(rotors, reflector, positions);

    std::string enigma_ct = enigma.encrypt(plaintext);

    
    EnigmaCipher enigma2(rotors, reflector, positions);
    std::string pt = enigma2.decrypt(enigma_ct);

    std::cout << "Enigma Cipher:\n";
    std::cout << "Ciphertext: " << enigma_ct << "\n";
    std::cout << "Decrypted : " << pt << "\n";
        }
  }

       else if(choice==2){

            menu::cryptanalysis_menu();

            int c;
            std::cin>>c;

            CaesarCipher caesar(3);
            std::string caesar_ct=caesar.encrypt(plaintext);

            VigenereCipher vig("LEMON");
            std::string vig_cipher=vig.encrypt(plaintext);

            MonoalphabeticCipher mono("QWERTYUIOPASDFGHJKLZXCVBNM");
            std::string mono_ct=mono.encrypt(plaintext);

            std::vector<std::vector<int>> key={{3,3},{2,5}};
            HillCipher hill(key);
            std::string hill_ct=hill.encrypt(plaintext);

            PlayfairCipher playfair("MONARCHY");
            std::string pf_ct=playfair.encrypt(plaintext);

            EnigmaCipher enigma(rotors, reflector, "AAA");
            std::string enigma_ct=enigma.encrypt(plaintext);

    if(c==1){
    std::cout<<"\n==== Caesar Cryptanalysis ====\n";
    caesar_attack::break_caesar(caesar_ct);
 }

    else if(c==2){
    std::cout<<"\n==== Vigenere Cryptanalysis ====\n";
    vigenere_attack::guess_key_length(vig_cipher);
 }
    else if(c==3){
     std::cout<<"\n==== Monoalphabatic Cryptanalysis ====\n";
     monoalphabetic_attack::break_mono(mono_ct);
 }
     else if(c==4){
      std::cout<<"\n==== Hill Cryptanalysis ====\n";
    hill_attack::known_plain_attack(
                    plaintext.substr(0,4),
                    hill_ct.substr(0,4)
                );

 }
      else if(c==5){
      std::cout<<"\n==== Playfair Cryptanalysis ====\n";
     playfair_attack::analyze_digraphs(pf_ct);
 }
     else if(c==6){

      std::cout<<"\n==== Enigma Cryptanalysis ====\n";

enigma_attack::brute_force_position(
    enigma_ct,
    "WELCOME",
    rotors,
    reflector
          );
      }
    }
 else if(choice==3){

            std::cout<<"\nExiting program...\n";
            break;

        }

    }


    return 0;

}