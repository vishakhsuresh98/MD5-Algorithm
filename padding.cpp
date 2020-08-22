#include "padding.h"

string padding(string input)
{
    string output = "";
    string pad = "1";
    while((input.length() + pad.length()) % 512 != 448) {
        pad += "0" ;
    }
    output = input + pad;
    return output;
}