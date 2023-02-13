// Alignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Mystruct {
    char cval1;
    int ival1;
    short sval1;
    char cval2;
};

struct short_short_short {
    short s1;
    short s2;
    short s3;
};

struct short_short_short_int {
    short s1;
    short s2;
    short s3;
    int i1;
};

struct char_char_int {
    char c1;
    char c2;
    int i1;
};

struct char_int_char {
    char c1;
    int i1;
    char c2;
};

struct int_int {
    int d1;
    int i1;
};

struct double_int {
    double d1;
    int i1;
};

struct char5_int {
    char ca1[5];
    int i1;
};

struct char8_int {
    char ca1[8];
    int i1;
};

struct char5_double {
    char ca1[5];
    double d1;
};

struct char8_double {
    char ca1[8];
    double d1;
};

struct char8_int_double {
    char ca1[8];
    int i1;
    double d1;
};

int main()
{
    std::cout << "Hello World!\n";

    std::cout << "size of Mystruct: " << sizeof(Mystruct) << '\n';

    //boundary 
    //padding = doldurma uygulanır 
    // Shows the actual memory layout
    /*
    struct Mystruct_
    {
        char cval1;            // 1 byte
        char _pad0[3];     // padding to put 'b' on 4-byte boundary
        int ival1;            // 4 bytes
        short sval1;          // 2 bytes
        char cval2;           // 1 byte
        char _pad1[1];    // padding to make sizeof(x_) multiple of 4
    };
    */

    std::cout << "short_short_short: " << sizeof(short_short_short) << '\n';
    std::cout << "short_short_short_int: " << sizeof(short_short_short_int) << '\n';
    std::cout << "char_char_int: " << sizeof(char_char_int) << '\n';
    std::cout << "char_int_char: " << sizeof(char_int_char) << '\n';
    std::cout << "int_int: " << sizeof(int_int) << '\n';
    std::cout << "double_int: " << sizeof(double_int) << '\n';
    std::cout << "char5_int: " << sizeof(char5_int) << '\n';
    std::cout << "char8_int: " << sizeof(char8_int) << '\n';
    std::cout << "char5_double: " << sizeof(char5_double) << '\n';
    std::cout << "char8_double: " << sizeof(char8_double) << '\n';
    std::cout << "char8_int_double: " << sizeof(char8_int_double) << '\n';

    /*
    (The entire structure is aligned on a boundary at least as big as 
    the biggest value in the structure)
    */

    struct char_int {
        char cval;
        int ival;
    };

    struct char_int mySt;

    mySt.cval = 0x41;
    mySt.ival = 0x33323130;

    char* cptr = reinterpret_cast<char*> (&mySt);
    std::cout << "char_int size: " << sizeof(char_int) << '\n';
    for (int i{ 0 }; i < sizeof(char_int); i++) {
        std::cout << i <<". byte of mySt : " << *cptr++ << '\n';
    }

    struct char_char_int {
        char cval1;
        char cval2;
        int ival1;
    };

    struct char_char_int mySt2;

    mySt2.cval1 = 0x41;
    mySt2.cval2 = 0x42;
    mySt2.ival1 = 0x33323130;

    char* cptr2 = reinterpret_cast<char*> (&mySt2);
    std::cout << "char_char_int size: " << sizeof(char_char_int) << '\n';
    for (int i{ 0 }; i < sizeof(char_char_int); i++) {
        std::cout << i << ". byte of mySt : " << *cptr2++ << '\n';
    }

}

