#include "binary_add.h"

/**
 * Compute the sum of 2 strings provided as input
 *
 * @param input_1 the first input, as a string in binary number system
 * @param input_2 the second input, as a string in binary number system
 * @returns the sum of the inputs, as a string in binary number system
 */
// string binary_add(string input_1, string input_2)
// {
//     string output = "";
//     int carry = 0;
//     int bit;
//     for(int i = input_1.size() - 1; i >= 0; i--) {
//         if((input_1[i] == '1') && (input_2[i] == '1')) {
//             bit = carry;
//             carry = 1;
//         }
//         else if((input_1[i] == '1') || (input_2[i] == '1')) {
//             bit = 1 - carry;
//         }
//         else {
//             bit = carry;
//             carry = 0; 
//         }
//         //add bit to output
//         if(bit == 0) {
//             output += '0';
//         }
//         else {
//             output += '1';
//         }
//     }

//     return output;
// }

// string binary_add(string s1, string s2, string s3, string s4, string s5)
// {
//     string output = "";
//     int output_array[32] = {};

//     int carry = 0;
//     for(int i = s1.size() - 1; i >= 0; i--) {
//         // int sum_of_bits = (int)s1[i] + (int)s2[i] + (int)s3[i] + (int)s4[i] + (int)s5[i] - 5 * 48
//         int sum_of_bits = 0;
//         if(s1[i] == '1') {
//             sum_of_bits ++;
//         }
//         if(s2[i] == '1') {
//             sum_of_bits ++;
//         }
//         if(s3[i] == '1') {
//             sum_of_bits ++;
//         }
//         if(s4[i] == '1') {
//             sum_of_bits ++;
//         }
//         if(s5[i] == '1') {
//             sum_of_bits ++;
//         }
//         sum_of_bits += carry;
//         output_array[i] = sum_of_bits % 2;
//         carry = sum_of_bits / 2;
//     }

//     for(int i = 0; i < s1.size(); i++) {
//         if(output_array[i] == 0) {
//             output += '0';
//         }
//         else {
//             output += '1';
//         }
//     }
//     return output;
// }


string binary_add(string s1, string s2)
{
    string output = "";
    int output_array[32] = {};

    int carry = 0;
    for(int i = s1.size() - 1; i >= 0; i--) {
        // int sum_of_bits = (int)s1[i] + (int)s2[i] + (int)s3[i] + (int)s4[i] + (int)s5[i] - 5 * 48
        int sum_of_bits = 0;
        if(s1[i] == '1') {
            sum_of_bits ++;
        }
        if(s2[i] == '1') {
            sum_of_bits ++;
        }
        
        sum_of_bits += carry;
        output_array[i] = sum_of_bits % 2;
        carry = sum_of_bits / 2;
    }

    for(int i = 0; i < s1.size(); i++) {
        if(output_array[i] == 0) {
            output += '0';
        }
        else {
            output += '1';
        }
    }
    return output;
}