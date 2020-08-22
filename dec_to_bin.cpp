#include "dec_to_bin.h"

/**
 * Convert a number (0 to 15) in decimal system to hexadecimal system
 *
 * @param dec the input number, as an int in decimal number system
 * @returns the equivalent string, in the hexadecimal number system
 */
string dec_to_bin(int dec)
{
    string bin = "0000000000000000000000000000000000000000000000000000000000000000";
    int i = 63;
    while(dec > 0) {
        if(dec % 2 == 1) {
            bin[i] = '1';
        }
        dec /= 2;
        i--;
    }
    return bin;
}