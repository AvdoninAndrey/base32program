#pragma once
#include <string>
using namespace std;
class MyException // абстрактный класс исключений 
{
protected:
    string error; // описание ошибки
    string correction; // исправление ошибки
    int num; // код ошибки
public:
    virtual void code () = 0;
    virtual void what() = 0;
    virtual void Fix() = 0;
};
