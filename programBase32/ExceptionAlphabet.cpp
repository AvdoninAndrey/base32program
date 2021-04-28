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

        size_t equally = data.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ234567");
        if (equally != string::npos) {
            data.erase(remove(data.begin(), data.end(), '='), data.end());
            size_t ClearTextSize = data.length();
            if (equally != ClearTextSize) {
                throw ExceptionAlphabet(2, "неправильное использование символа \"=\".", "Символ \"=\" можно использовать только после символом букв анлийского алфавита");
            }
        }
        return true;
    } catch (ExceptionAlphabet& ex) {
        ex.code();
        ex.what();
        ex.Fix();
        return false;
    }
}
