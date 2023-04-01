#pragma once

#include <iostream>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <deque>

#define ptr(str) std::cout << str << std::endl
#define err(str) std::cerr << str << std::endl
#define enable_bit(ptr, num) *(ptr + num / 8) |= (1 << (num % 8))
#define disable_bit(ptr, num) *(ptr + num / 8) &= ~(1 << (num % 8))
/**
 * This forces compiler to inline a specific function.
*/
#define Inline inline __attribute__((always_inline))

namespace SF{
    /**
     * A multiplication function used for testing
    */
    Inline int mul(int a, int b);
    
    /**
     * A function that gets a specific bit from a uint8 pointer and returns a boolean
     * \param a The uint8 pointer pointing to the heap
     * \param pos The position of the bit reletive to the least significant bit
     * \return A boolean value representing the bit
    */
    bool get_bit(uint8_t* a, size_t pos);

    /**
     * A signed version of the get_bit function which gets a specific bit from a signed integer pointer.
     * \param a The signed int pointer pointing to the heap
     * \param pos The position of the bit reletive to the least significant bit
     * \return A boolean value representing the bit
    */
    bool sget_bit(int8_t* a, size_t pos);
    
    /**
     * Add two blocks of memory by adding the bits in the memory.
     * The size of the two pointers need to be the same for this function to run properly.
     * \param a The first pointer
     * \param b The second pointer
     * \param size The size of the pointers in bytes
    */
    uint8_t* bit_add(uint8_t* a, uint8_t* b, size_t size);

    /**
     * A signed version of the bit_add function
     * \param a The first pointer
     * \param b The second pointer
     * \param size The size of the pointers in bytes
    */
    int8_t* sbit_add(int8_t* a, int8_t* b, size_t size);

    /**
     * Divides a string by 2 as if it's an integer.
     * \param str The input that is being divided by 2
     * \param remainder The variable that the remainder will be stored in. Replace with NULL if the remainder is not required
     * \return An std::string that is the result of the division
    */
    std::string half(std::string str, bool* remainder);

    /**
     * Converts a deque filled with characters into a std::string.
     * \param stack The stack of characters
     * \return A std::string that is converted from a deque
    */
    std::string deque_to_str(std::deque<char> deque);

    /**
     * Removes the zeros as the start of a std::string.
     * \param str The input string
     * \return String with no zeros in front.
    */
    std::string remove_zeros(std::string str);
};