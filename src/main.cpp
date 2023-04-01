#include <lib.hpp>
#include <iostream>

int main(int argc, char *argv[]){
    // Demonstation
    std::string x = SF::Half("18446744073709551616", NULL);
    ptr(x);
    x = SF::Double("9223372036854775808");
    ptr(x);
    return 0;
}
