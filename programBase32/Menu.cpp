#include "Menu.h"
void Menu::Select()
{
    bool flag, isTrue = true;
    string s,mode,NeMode;
    cout << "Добро пожаловать в программу для кодирования-декодирования Base32." << endl;
    Help help;
    help.printHelp();
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
            ExceptionDecodeStroka check;
            try {
                check.checking_the_alphabetB32(s);
                Decoder b32;
                cout << "Data for decoding: " << s << endl;
                cout <<"Decoded string: ";
                Result<Decoder>::PrintResult(b32.base32Decode(s));
            } catch (ExceptionDecodeStroka & ex) {
                ex.code();
                ex.what();
                ex.Fix();
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
