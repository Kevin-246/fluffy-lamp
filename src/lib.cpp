#include <lib.hpp>

inline int SF::mul(int a, int b){
    return a * b;
}

bool SF::get_bit(uint8_t* a, size_t pos){
    size_t byte_index = pos / 8;
    size_t bit_offset = pos % 8;

    uint8_t byte_value = *(a + byte_index);
    bool bit = byte_value & (1 << bit_offset);
    return bit;
}

bool SF::sget_bit(int8_t* a, size_t pos){
    size_t byte_index = pos / 8;
    size_t bit_offset = pos % 8;

    int8_t byte_value = *(a + byte_index);
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

int8_t* SF::sbit_add(int8_t* a, int8_t* b, size_t size){
    int8_t* result = reinterpret_cast<int8_t*>(std::calloc(size, sizeof(int8_t)));
    bool num1;
    bool num2;
    bool carry = 0;
    int sum;
    for(size_t i = 0; i < size * 8; i++){
        num1 = SF::sget_bit(a, i);
        num2 = SF::sget_bit(b, i);
        sum = num1 + num2 + carry;
        switch(sum){
            case 1:
                carry = 0;
                enable_bit(result, i);
                break;
            case 2:
                carry = 1;
                break;
            case 3:
                carry = 1;
                enable_bit(result, i);
                break;
            default:
                carry = 0;
                break;
        }
    }
    return result;
}

std::string SF::half(std::string str, bool* remainder){
    std::string result;
    int a;
    int b = str[0];
    int quotient;
    bool has_remainder = false;
    for(size_t i = 0; i < str.size(); i++){
        a = b - '0';
        if(i == str.size() - 1){
            has_remainder = a % 2;
        }
        b = str[i + 1];
        quotient = a / 2;
        if(a % 2 == 1){
            b += 10;
        }
        result += quotient + '0';
    }
    result = SF::remove_zeros(result);
    if(remainder == NULL) return result;
    if(has_remainder) *remainder = true;
    return result;
}

std::string SF::deque_to_str(std::deque<char> deque){
    std::string result(deque.begin(), deque.end());
    return result;
}

std::string SF::remove_zeros(std::string str){
    std::size_t pos = str.find_first_not_of('0');
    if(pos != std::string::npos){
        return str.substr(pos);
    }
    return "0";
}