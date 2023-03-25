#include <lib.hpp>
#include <iostream>

int main(int argc, char *argv[]){
    // Demonstation
    uint8_t* a = new uint8_t;
    uint8_t* b = new uint8_t;
    *a = 12;
    *b = 33;
    uint8_t* c = SF::bit_add(a, b, 1);
    printf("%d\n", *c);
    delete a;
    delete b;
    delete c;
    return 0;
}
