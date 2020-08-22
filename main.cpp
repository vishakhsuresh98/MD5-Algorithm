#include <time.h>

#include "encrypt.h"
#include "alphabet_to_hex.h"
#include "hex_to_bin.h"
#include "bin_to_hex.h"


// Driver program to test the above functions 
int main() 
{  
    srand(time(NULL));
    ifstream in_ptr;
    ofstream out_ptr;

    cout << "SHA-1" << endl;
    cout << "-----\n\n" << endl;

    // encryption process
    string plaintext;
    in_ptr.open("plaintext.txt"); 
    getline(in_ptr, plaintext);
    cout << "Plaintext - " << plaintext << endl;
    plaintext = alphabet_to_hex(plaintext);
    // plaintext = "616263";
    plaintext = hex_to_bin(plaintext);
    
    string message_digest = encrypt(plaintext); 
    message_digest = bin_to_hex(message_digest);
    cout << "Message digest - " << message_digest << endl; 
    cout << "\n\n";
    in_ptr.close();

    return 0; 
} 
