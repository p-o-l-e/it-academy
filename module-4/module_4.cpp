#include "module_4.h"

const int check_n_shift(const int& value, const int& s)
{
    return ((value & 0b1) || (value < 0)) ? value >> s : value << s;
}