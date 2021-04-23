#pragma once
#include <iostream>
template <typename T>
class Result
{

public:
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
