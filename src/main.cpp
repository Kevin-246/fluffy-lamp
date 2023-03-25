#include <lib.hpp>
#include <iostream>

int main(int argc, char *argv[]){
    // Demonstation
    int8_t* a = new int8_t;
    int8_t* b = new int8_t;
    *a = -12; 
    *b = 33;
    int8_t* c = SF::sbit_add(a, b, 1);
    printf("%d\n", *c);
    delete a;
    delete b;
    delete c;
    return 0;
}
