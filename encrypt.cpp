#include "encrypt.h"
#include "padding.h"
#include "append_length.h"
#include "hex_to_bin.h"
#include "get_constant_k.h"
#include "get_process_p.h"
#include "get_w.h"
#include "shift_left.h"
#include "binary_add.h"
#include "get_shift.h"
#include "bin_to_hex.h"

string encrypt(string input) 
{
    string padded_input = padding(input);
    input = append_length(input, padded_input);
    int n = input.length() / 512;

    // string a = hex_to_bin("01234567");
    // string b = hex_to_bin("89ABCDEF");
    // string c = hex_to_bin("FEDCBA98");
    // string d = hex_to_bin("76543210");

    string a = hex_to_bin("67452301");
    string b = hex_to_bin("EFCDAB89");
    string c = hex_to_bin("98BADCFE");
    string d = hex_to_bin("10325476");

    cout<<"abcd = "<<bin_to_hex(a)<<" "<<bin_to_hex(b)<<" "<<bin_to_hex(c)<<" "<<bin_to_hex(d)<<endl;

    string h0 = a;
    string h1 = b;  
    string h2 = c;
    string h3 = d;
    
    for(int i = 0; i < n; i++) {
        string block = input.substr(i * 512, 512);
        string* w = get_w(block);
        for(int j = 0; j < 64; j++) {
            cout << "iter "<<j<<": ";
            string k = get_constant_k(j);
            int shift = get_shift(j);
            
            string p = get_process_p(j, b,c,d);
            string temp = binary_add(shift_left(binary_add(binary_add(binary_add(a, p), w[j]), k), shift), b);
            a = d;
            d = c;
            c = b;
            b = temp;

            // string temp_a = a;
            // string temp_b = b;
            // string temp_c = c;
            // string temp_d = d;

            // if(j%4==0) {
            //     string p = get_process_p(j, b,c,d);
            //     string temp = binary_add(shift_left(binary_add(binary_add(binary_add(a, p), w[j]), k), shift), b);
            //     a = temp;
            //     b = temp_b;
            //     c = temp_c;
            //     d = temp_d;
            // }
            // else if(j%4==1) {
            //     a = temp_d;
            //     b = temp_a;
            //     c = temp_b;
            //     d = temp_c;
            //     string p = get_process_p(j, b,c,d);
            //     string temp = binary_add(shift_left(binary_add(binary_add(binary_add(a, p), w[j]), k), shift), b);
            //     a = temp_a;
            //     b = temp_b;
            //     c = temp_c;
            //     d = temp;
            // }      
            // else if(j%4==2) {                
            //     a = temp_c;
            //     b = temp_d;
            //     c = temp_a;
            //     d = temp_b;
            //     string p = get_process_p(j, b,c,d);
            //     string temp = binary_add(shift_left(binary_add(binary_add(binary_add(a, p), w[j]), k), shift), b);
            //     a = temp_a;
            //     b = temp_b;
            //     c = temp;
            //     d = temp_d;
            // }       
            // else if(j%4==3) {
            //     a = temp_b;
            //     b = temp_c;
            //     c = temp_d;
            //     d = temp_a;
            //     string p = get_process_p(j, b,c,d);
            //     string temp = binary_add(shift_left(binary_add(binary_add(binary_add(a, p), w[j]), k), shift), b);                
            //     a = temp_a;
            //     b = temp;
            //     c = temp_c;
            //     d = temp_d;
            // }                     

            cout<<bin_to_hex(a)<<" "<<bin_to_hex(b)<<" "<<bin_to_hex(c)<<" "<<bin_to_hex(d)<<endl;
        }
        h0 = binary_add(h0, a);
        h1 = binary_add(h1, b);
        h2 = binary_add(h2, c);
        h3 = binary_add(h3, d);
    }
    string message_digest = h0 + h1 + h2 + h3;
    return message_digest;
}