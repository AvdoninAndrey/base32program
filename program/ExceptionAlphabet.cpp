#include "ExceptionAlphabet.h"

ExceptionAlphabet::ExceptionAlphabet (const int &num,const string &error,const string & correction) // конструктор с параметрами (код ошибки и описание ошибки)
{
    this->num = num;
    this->error = error;
    this->correction = correction;
}

void ExceptionAlphabet::what ()
{
    cout << "Код ошибки: " << num << endl << "Описание ошибки: " << error << endl << correction << endl;
}

bool ExceptionAlphabet::checking_the_alphabetB32(string &data)
{
    Alphabets b32;
    try {
        if (data.find_first_not_of(b32.base32alphabet,0) != string::npos) {
            throw ExceptionAlphabet(1, "наличие недопустимых символов.", "Используйте следующий алфавит: " + b32.base32alphabet);
        }
        return true;
    } catch (ExceptionAlphabet& ex) {
        ex.what() ;
        return false;
    }
}
