/**
* @file Decoder.h
* @author Авдонин А.Д.
* @version 1.0
* @copyright ИБСТ ПГУ
*/
#pragma once
#include "Alphabet.h"
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
    Decoder(const string str);
    Decoder base32Decode(string data); // декодирование
    friend bool operator ==(const Decoder & left, const Decoder & right);
    friend ostream & operator<<(ostream &out, const Decoder &a); // перегрузка <<
};
