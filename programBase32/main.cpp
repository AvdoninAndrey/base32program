#include "program.h"
using namespace std;

class Menu
{
private:
    const string dec = "Decode", enc = "Encode", contin = "not";
    const string ex = "exit", spravka = "help";
    string  mode, NeMode;
public:

    void Select()
    {
        bool flag, isTrue = true;
        string s;
        cout << "Добро пожаловать в программу для кодирования-декодирования Base32." << endl;
        cout << "Чтобы завершить работу программу, введите \"exit\"." << endl;
        do {
            cout << "Укажите режим работы: ";
            cin >> mode;
            if (mode == enc) {
                cout << "Введите строку для кодирования: ";
                cin.get();
                getline(cin, s);
                Encoder b32;
                cout << "Encoding data: " << s << endl;
                cout <<"Encoded string: ";
                Result<Encoder>::PrintResult(b32.base32Encode(s));
            }
            if (mode == dec) {
                cout << "Введите строку для декодирования: ";
                cin.get();
                getline(cin, s);
                ExceptionAlphabet check;
                if(check.checking_the_alphabetB32(s)) {
                    Decoder b32;
                    cout << "Data for decoding: " << s << endl;
                    cout <<"Decoded string: ";
                    Result<Decoder>::PrintResult(b32.base32Decode(s));
                }
            }
            if (mode == ex) {
                cout << "Программа завершила работу." << endl;
                isTrue = false;
                break;
            }
            if (mode != enc && mode != dec && mode != ex) {

                cout << "Чтобы воспользоваться справкой, введите \"help\"." << endl;
                cout << "Иначе введите \"not\" , чтобы продолжить.\n";
                cin >> NeMode;
                if (NeMode == spravka) {
                    Help help;
                    help.printHelp();
                }
                if (NeMode != contin && NeMode != spravka) {
                    do {
                        cout << "Пожалуйста, введите что-то из указанных команд выше:" << endl;
                        cin >> NeMode;
                        flag = true;
                        if (NeMode == spravka) {
                            Help help;
                            help.printHelp();
                            flag = false;
                            break;
                        } else if (NeMode == contin) {
                            NeMode = mode;
                            flag = false;
                            break;
                        }
                    } while (flag != false);
                }

            }
        } while (isTrue != false);
    }

};

int main()
{
    Menu polzovatel;
    polzovatel.Select();
    return 0;
}
