#include "ExceptionAlphabet.h"

ExceptionAlphabet::ExceptionAlphabet (const int &num,const string &error,const string & correction) // конструктор с параметрами (код ошибки ,описание ошибки и исправление)
{
    this->num = num;
    this->error = error;
    this->correction = correction;
}

void ExceptionAlphabet::what  ()
{
    cerr << "Описание ошибки: " << error << endl;
}
void ExceptionAlphabet::code ()
{
    cerr << "Код ошибки: " << num << endl;
}

void ExceptionAlphabet::Fix ()
{
    cout  << correction << endl;
}

bool ExceptionAlphabet::checking_the_alphabetB32(string data)
{

    try {
        if (data.find_first_not_of(base32alphabet,0) != string::npos) {
            throw ExceptionAlphabet(1, "наличие недопустимых символов.", "Используйте следующий алфавит: " + base32alphabet);
        }
        return true;
    } catch (ExceptionAlphabet& ex) {
        ex.code();
        ex.what();
        ex.Fix();
        return false;
    }
}
