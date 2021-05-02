/**
* @file Exception.h
* @author Авдонин А.Д.
* @version 1.0
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <string>
using namespace std;
///@brief Абстрактный класс для иcключений
class MyException  
{
protected:
    ///@details атрибут, хранящий описание ошибки
    string error; 
    ///@details атрибут, хранящий информацию об исправлении ошибки
    string correction; 
    ///@details атрибут, хранящий информацию о коде ошибки
    int num; 
public:
     ///@brief Чисто виртуальный метод. 
     ///@details Предназначен для вывода кода ошибки.
    virtual void code () = 0;
    ///@brief Чисто виртуальный метод.
    ///@details Предназначен для вывода описания ошибки.
    virtual void what() = 0;
    ///@brief Чисто виртуальный метод.
    ///@details Предназначен для вывода информации об исправлении ошибки.
    virtual void Fix() = 0;
};
