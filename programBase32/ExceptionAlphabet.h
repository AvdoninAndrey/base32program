#pragma once
#include "Alphabets.h"
#include <iostream>
#include "Exception.h"
class ExceptionAlphabet : public Alphabets, protected Exception
{
public:
ExceptionAlphabet (const int &num,const string &error,const string & correction);
void what ();
static bool checking_the_alphabetB32(string &data);
};
