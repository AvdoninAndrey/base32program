#pragma once
#include "Alphabets.h"
#include <iostream>
#include <vector>
class Encoder: public Alphabets
{
private:
    const int b32key = 5; // ключ Base32
    char * stroka;
    int len;
    vector<char> B32bit_operations(unsigned long long int &buffer, int &bitCount); // битовые операции в Base32

    vector<char> Base_equally (vector <char> res); // = в Base32

public:
    char& operator[] (const int index); // перегрузка []

    Encoder base32Encode(string &data); // кодированиe

    Encoder(const int size);   // конструктор с параметром

    Encoder(); // конструктор по умолчанию

    ~Encoder(); // деструктор
    friend ostream & operator<<(ostream &out, const Encoder &a); // перегрузка <<

};
