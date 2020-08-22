#include "binary_and.h"

/**
 * Compute the AND of 2 strings provided as input
 *
 * @param input_1 the first input, as a string in binary number system
 * @param input_2 the second input, as a string in binary number system
 * @returns the AND of the inputs, as a string in binary number system
 */
string binary_and(string input_1, string input_2)
{
    string output = "";
    for(int i = 0; i < input_1.size(); i++) {
        if((input_1[i] == '0') || (input_2[i] == '0')) {
            output += '0';
        }
        else {
            output += '1';
        }
    }
    return output;
}