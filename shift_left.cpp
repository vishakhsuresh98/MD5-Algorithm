#include "shift_left.h"

/**
 * Perform left shift operation on a string provided as input
 *
 * @param input the input string, in binary number system
 * @param shift the shift required, as an int
 * @returns the output after shifting, as a string in binary number system
 */
string shift_left(string input, int shift)
{
    string output = "";
    for(int i = 0; i < input.size(); i++) {
        output += input[(i + shift) % input.size()]; 
    }
    return output;
}