#include "binary_not.h"

/**
 * Compute the NOT of a string provided as input
 *
 * @param input the  input, as a string in binary number system
 * @returns the NOT of the inputs, as a string in binary number system
 */
string binary_not(string input)
{
    string output = "";
    for(int i = 0; i < input.size(); i++) {
        if(input[i] == '0') {
            output += '1';
        }
        else {
            output += '0';
        }
    }
    return output;
}