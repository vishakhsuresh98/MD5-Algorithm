#include "get_process_p.h"
#include "binary_and.h"
#include "binary_or.h"
#include "binary_not.h"
#include "binary_xor.h"

string get_process_p(int round, string b, string c, string d)
{
    string p;
    if(round <= 15) {
        p = binary_or(binary_and(b, c), binary_and(binary_not(b), d));
    }
    else if(round <= 31) {
        p = binary_or(binary_and(b, d), binary_and(c, binary_not(d)));
    }
    else if(round <= 47) {
        p = binary_xor(binary_xor(b, c), d);
    }
    else {
        p = binary_xor(c, binary_or(b, binary_not(d)));
    }
    return p;
}