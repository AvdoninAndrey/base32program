#pragma once
#include "Alphabet.h"
#include <iostream>
#include <vector>
#include <algorithm>
class Decoder: protected Alphabets
{
private:
    const int b32key = 5; // ключ Base32
    string stroka;
public:
    char& operator[] (const int index); // перегрузка []
    Decoder () = default;
    ~Decoder () = default;
    Decoder(const char * str);
    Decoder base32Decode(string data); // декодирование
    friend bool operator ==(const Decoder & left, const Decoder & right);
    friend ostream & operator<<(ostream &out, const Decoder &a); // перегрузка <<
};
