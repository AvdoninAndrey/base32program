/**
* @file Result.h
* @author Авдонин А.Д.
* @version 1.0
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <iostream>
template <typename T>
///@brief Класс для вывода результа кодирования или декодирования
class Result
{

public:
    ///@brief  выводит результат кодирования или декодирования Base32
    static void PrintResult (T result);
};

template <typename T>
void Result<T>::PrintResult(T result)
{
    for (int i=0; result[i]!='\0'; i++) {
        cout << result[i];
    }
    cout << endl;
}
