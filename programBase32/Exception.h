/**
* @file Exception.h
* @author Авдонин А.Д.
* @version 1.0
* @brief Описание класса MyException
* @data 03.05.2021
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <string>
using namespace std;
///@brief Абстрактный класс для иcключений
class MyException  
{
protected:
    ///@brief атрибут, хранящий описание ошибки
    string error; 
    ///@brief атрибут, хранящий информацию об исправлении ошибки
    string correction; 
    ///@brief атрибут, хранящий информацию о коде ошибки
    int num; 
public:
     ///@brief Чисто виртуальный метод. Предназначен для вывода кода ошибки. 
    virtual void code () = 0;
    ///@brief Чисто виртуальный метод. Предназначен для вывода описания ошибки.
    virtual void what() = 0;
    ///@brief Чисто виртуальный метод. Предназначен для вывода информации об исправлении ошибки.
    virtual void Fix() = 0;
};
