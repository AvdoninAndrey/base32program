/**
* @file Result.h
* @author Авдонин А.Д.
* @version 1.0
* @brief Описание шаблонного класса Result<T> и его реализация
* @date 03.05.2021
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
    /**@details вывод осущетсвляется через цикл
      @code 
      for (int i=0; result[i]!='\0'; i++) {
                cout << result[i];
        }
      @endcode 
     */
    
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
