#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdlib>

#define log(str) std::cout << str << std::endl
#define enable_bit(ptr, num) *(ptr + num / 8) |= (1 << (num % 8))
#define disable_bit(ptr, num) *(ptr + num / 8) &= ~(1 << (num % 8))

namespace SF{
    int mul(int a, int b);
    bool get_bit(uint8_t* a, size_t pos);
    bool sget_bit(int8_t* a, size_t pos);
    uint8_t* bit_add(uint8_t* a, uint8_t* b, size_t size);
    int8_t* sbit_add(int8_t* a, int8_t* b, size_t size);
};