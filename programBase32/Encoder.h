#pragma once
#include "Alphabet.h"
#include <iostream>
#include <vector>
class Encoder: protected Alphabets
{
private:
    const int b32key = 5; // ключ Base32
     string stroka;
    vector<char> B32bit_operations(unsigned long long int &buffer, int &bitCount); // битовые операции в Base32
    vector<char> Base_equally (vector <char> res); // = в Base32

public:
    char& operator[] (const int index); // перегрузка []
    Encoder () = default;
    ~Encoder() = default;
    Encoder (const string str);
    friend bool operator == (const Encoder & left, const Encoder & right);
    Encoder base32Encode(string data); // кодированиe
    friend ostream & operator<<(ostream &out, const Encoder &a); // перегрузка <<
};
