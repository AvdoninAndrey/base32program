#pragma once
#include <string>
using namespace std;
class Exception // абстрактный класс исключений
{
protected:
    string error; // описание ошибки
    string correction; // исправление ошибки
    int num; // код ошибки
public:
    virtual void what () = 0; 
};
