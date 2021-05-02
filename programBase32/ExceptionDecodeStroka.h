/**
* @file ExceptionDecodeStroka.h
* @author Авдонин А.Д.
* @version 1.0
* @copyright ИБСТ ПГУ
*/
#pragma once
#include "Alphabet.h"
#include <iostream>
#include "Exception.h"
#include <algorithm>
///@brief Класс для исключений строки при декодировании
class ExceptionDecodeStroka : protected Alphabets, protected MyException
{
public:
    ///@brief Конструктор по умолчанию
    ExceptionDecodeStroka() = default;
    ///@brief Деструктор по умолчанию
    ~ExceptionDecodeStroka() = default;
    ///@brief Конструктор с параметрами
    /**
     * @param num - хранит информацию о коде ошибки.
     * @param error - хранит описание ошибки.
     * @param correction - хранит информацию об исправлении ошибки.
     * */
    ExceptionDecodeStroka(const int &num,const string &error,const string & correction);
    void what () override;
    void code () override;
    void Fix () override;
    ///@brief Метод, проверяющий строку при декодировании на наличие ошибок
    /**@details В первую очередь, строка проверяется на алфавит Base32.
     * Затем строка проверяется на правильное использование символа "=".
     * @param data - строка, которую нужно проверить при декодировании.
     * @return значение "true", если проверки завершились успешно.
     * @throw  ExceptionDecodeStroka, если в строке есть символы, не принадлежащие алфавиту Base32 и при неправильном использовании символа "=".
    */
    bool checking_the_alphabetB32(string data);
};
