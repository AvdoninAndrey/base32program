/**
* @file ExceptionDecodeStroka.h
* @author Авдонин А.Д.
* @version 1.0
* @brief Описание класса ExceptionDecodeStroka
* @date 03.05.2021
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
    /**@brief Конструктор с параметрами
     * @param num - целочисленное число, хранящее информацию о коде ошибки.
     * @param error - строка, хранящая описание ошибки.
     * @param correction - строка, хранящая информацию об исправлении ошибки.
     */
    ExceptionDecodeStroka(const int &num,const string &error,const string & correction);
    void what () override;
    void code () override;
    void Fix () override;
    ///@brief Метод, проверяющий строку при декодировании на наличие ошибок
    /**@details <p>В первую очередь, строка проверяется на алфавит Base32.
     *Затем строка проверяется на правильное использование символа "=": <br>
     * находится позиция первого символа "=". Если данный символ присутствует, то все символы "=" удалются из строки. 
     * Далее считается новая длина строки. И если новая длина не равна
     * найденной позиции первого символа "=", то бросается исключение. </p>
     * @param data - std::string, строка которую нужно проверить при декодировании.
     * @return значение "true", если проверки завершились успешно.
     * @throw  ExceptionDecodeStroka, если в строке есть символы, не принадлежащие алфавиту Base32 и при неправильном использовании символа "=".
     */
    bool checking_the_Decod_str(string data);
};
