#include "append_length.h"
#include "dec_to_bin.h"

string append_length(string message, string padded_message)
{
    string output = "";
    int length = message.length();
    output = padded_message + dec_to_bin(length);
    return output;
}