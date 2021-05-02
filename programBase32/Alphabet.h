/**
* @file Alphabet.h
* @author Авдонин А.Д.
* @version 1.0
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <string>
using namespace std;
///@brief Класс хранит алфавит Base32
class Alphabets
{
protected:
///@brief Алфавит Base32
   const string base32alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567=";
};
