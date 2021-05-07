/**
* @file Alphabet.h
* @author Авдонин А.Д.
* @version 1.0
* @brief Описание класса Alphabets
* @date 03.05.2021
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
