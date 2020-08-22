#include "binary_or.h"

/**
 * Compute the OR of 2 strings provided as input
 *
 * @param input_1 the first input, as a string in binary number system
 * @param input_2 the second input, as a string in binary number system
 * @returns the OR of the inputs, as a string in binary number system
 */
string binary_or(string input_1, string input_2)
{
    string output = "";
    for(int i = 0; i < input_1.size(); i++) {
        if((input_1[i] == '1') || (input_2[i] == '1')) {
            output += '1';
        }
        else {
            output += '0';
        }
    }
    return output;
}