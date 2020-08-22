#include "dec_to_hex.h"

string dec_to_hex(int dec)
{
    unordered_map <int, string> mp; 
    mp[0] = "0"; 
    mp[1] = "1"; 
    mp[2] = "2"; 
    mp[3] = "3"; 
    mp[4] = "4"; 
    mp[5] = "5"; 
    mp[6] = "6"; 
    mp[7] = "7"; 
    mp[8] = "8"; 
    mp[9] = "9"; 
    mp[10] = "A"; 
    mp[11] = "B"; 
    mp[12] = "C"; 
    mp[13] = "D"; 
    mp[14] = "E"; 
    mp[15] = "F";

    string hex = mp[dec];  
    return hex;
}