#include "binary_xor.h"

/**
 * Compute the exclusive or of 2 strings provided as input
 *
 * @param input_1 the first input, as a string in binary number system
 * @param input_2 the second input, as a string in binary number system
 * @returns the XOR of the inputs, as a string in binary number system
 */
string binary_xor(string input_1, string input_2)
{
    string output = "";
    for(int i = 0; i < input_1.size(); i++) {
        if(input_1[i] == input_2[i]) {
            output += '0';
        }
        else {
            output += '1';
        }
    }
    return output;
}