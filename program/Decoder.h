#pragma once
#include "Alphabets.h"
#include <iostream>
#include <vector>
#include <algorithm>
class Decoder: public Alphabets
{
private:
    const int b32key = 5; // ключ Base32
    char * stroka;
    int len;
public:
    char& operator[] (const int index); // перегрузка []

    Decoder base32Decode(string &data); // декодирование

    Decoder(const int size);  // конструктор с параметром

    Decoder(); // конструктор по умолчанию

    ~Decoder(); // деструктор
    friend ostream & operator<<(ostream &out, const Decoder &a); // перегрузка <<
};
