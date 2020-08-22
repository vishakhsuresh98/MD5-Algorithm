#include "alphabet_to_hex.h"
#include "dec_to_hex.h"

/**
 * Convert a number in English to hexadecimal system
 *
 * @param alpha the input string, in English
 * @returns the equivalent string, in the hexadecimal number system
 */
string alphabet_to_hex(string alpha)
{
    string hex = ""; 
    for (int i = 0; i < alpha.length(); i++) { 
        int ascii = (int)(alpha[i]); 
        hex += dec_to_hex(ascii / 16);
        hex += dec_to_hex(ascii % 16);
    } 
    return hex;
}