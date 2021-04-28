#pragma once
#include "Alphabet.h"
#include <iostream>
#include "Exception.h"
#include <algorithm>
class ExceptionAlphabet : protected Alphabets, protected MyException
{
public:
    ExceptionAlphabet() = default;
    ~ExceptionAlphabet() = default;
    ExceptionAlphabet (const int &num,const string &error,const string & correction);
    void what () override;
    void code () override;
    void Fix () override;
    bool checking_the_alphabetB32(string data);
};
