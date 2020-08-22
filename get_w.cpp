#include "get_w.h"
#include "binary_xor.h"
#include "shift_left.h"

// 512 bit msg block as input
string* get_w(string input)
{
    static string w[64] = {};
    for(int i = 0; i <= 15; i++) {
        // for each 32 bit word, take lower order byte first
        string word = input.substr(i * 32, 32);
        w[i] = word.substr(24, 8) + word.substr(16, 8) + word.substr(8, 8) + word.substr(0, 8);
        // cout<<"w["<<i<<"] = "<<w[i]<<endl;
    }
    for(int i = 16; i <= 31; i++) {
        w[i] = w[(5 * i + 1) % 16];
        // cout<<"w["<<i<<"] = "<<w[i]<<endl;
    }   
    for(int i = 32; i <= 47; i++) {
        w[i] = w[(3 * i + 5) % 16];
        // cout<<"w["<<i<<"] = "<<w[i]<<endl;
    }
    for(int i = 48; i <= 63; i++) {
        w[i] = w[(7 * i) % 16];
        // cout<<"w["<<i<<"] = "<<w[i]<<endl;
    }
    return w;
}