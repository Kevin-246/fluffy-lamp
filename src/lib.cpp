#include <lib.hpp>

int SF::mul(int a, int b){
    return a * b;
}

bool SF::get_bit(uint8_t* a, size_t pos){
    size_t byte_index = pos / 8;
    size_t bit_offset = pos % 8;

    uint8_t byte_value = *(a + byte_index);
    bool bit = byte_value & (1 << bit_offset);
    return bit;
}

uint8_t* SF::bit_add(uint8_t* a, uint8_t* b, size_t size){
    uint8_t* result = reinterpret_cast<uint8_t*>(std::calloc(size, sizeof(uint8_t)));
    bool num1;
    bool num2;
    bool carry = 0;
    int sum;
    for(size_t i = 0; i < size * 8; i++){
        num1 = SF::get_bit(a, i);
        num2 = SF::get_bit(b, i);
        sum = num1 + num2 + carry;
        switch(sum){
            case 1:
                // Sum equals to 1
                carry = 0;
                enable_bit(result, i);
                break;
            case 2:
                // Sum equals to 2
                carry = 1;
                break;
            case 3:
                // Sum equals to 3
                carry = 1;
                enable_bit(result, i);
                break;
            default:
                // Sum equals to 0
                carry = 0;
                break;
        }
    }
    return result;
}