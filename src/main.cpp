#include <lib.hpp>
#include <cstdio>
#include <iostream>

int main(int argc, char *argv[]){
    // Demonstation
    std::string x = SF::Half("36893488147419103232"); // 36893488147419103232 is double 18446744073709551616
    ptr(x);
    x = SF::Double("9223372036854775808"); // 9223372036854775808 is half of 18446744073709551616
    ptr(x);
    uint8_t* p = SF::Str_to_bin("72", 128);
    printf("%d\n", *p);
    return 0;
}
