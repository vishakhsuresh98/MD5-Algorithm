#include "get_shift.h"

int get_shift(int round)
{
    /*
    7, 12, 17 and 22 for the round 1
    5, 9, 14 and 20 for the round 2
    4, 11, 16 and 23 for the round 3
    6, 10, 15 and 21 for the round 4
    */
    int shift;
    if(round <= 15) {
        int shift_array[4] = {7, 12, 17, 22};
        shift = shift_array[round % 4];
    }
    else if(round <= 31) {
        int shift_array[4] = {5, 9, 14, 20};
        shift = shift_array[round % 4];
    }
    else if(round <= 47) {
        int shift_array[4] = {4, 11, 16, 23};
        shift = shift_array[round % 4];
    }
    else {
        int shift_array[4] = {6, 10, 15, 21};
        shift = shift_array[round % 4];
    }
    return shift;
}