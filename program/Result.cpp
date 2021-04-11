#include "Result.h"

void Result::PrintResultEncod(Encoder result)
{
    cout << "Encoded string: ";
    for (int i=0; result[i]!='\0'; i++) {
        cout << result[i];
    }
    cout << endl;
}

void Result::PrintResultDecod (Decoder result)
{
    cout << "Decoded string: ";
    for (int i=0; result[i]!='\0'; i++) {
        cout << result[i];
    }
    cout << endl;
}
