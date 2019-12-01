#include <iostream>
#include <string>
using namespace std;


string encrypt_message(string message, string alphabet, string key){
    string encrypted_message{};
    for(char letter:message){
        size_t position {alphabet.find(letter)};
        if( position != string::npos ){
            char encrypted_letter = key[position];
            encrypted_message += encrypted_letter;
        } else {
            encrypted_message += letter;
        }
    }
    return encrypted_message;
}

string decrypt_message(string message, string alphabet, string key){
    string decrypted_message{};
    for(char letter:message){
        size_t position {key.find(letter)};
        if( position != string::npos ){
            char decrypted_letter = alphabet[position];
            decrypted_message += decrypted_letter;
        } else {
            decrypted_message += letter;
        }
    }
    return decrypted_message;
}


int main(){
    
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    
    cout << "Enter your message: " << endl;
    string message {};
    getline(cin, message);
    cout << "Message: " << message << endl;
    string encrypted_message {};
    encrypted_message = encrypt_message(message, alphabet, key);
    cout << "Encrypted message: " << encrypted_message << endl;
    string decrypted_message {};
    decrypted_message = decrypt_message(encrypted_message, alphabet, key);
    cout << "Decrypted message: " << decrypted_message << endl;
    return 0;
}
