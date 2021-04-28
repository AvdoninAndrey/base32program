#include "Decoder.h"

ostream & operator<<(ostream &out, const Decoder &a) // перегрузка <<
{
    out << a.stroka;
    return out;
}

Decoder::Decoder(const string str)
{
    int size_str= str.size();
    this->stroka.resize(size_str);
    this->stroka = str;
}
bool operator == (const Decoder & left, const Decoder & right)
{
    if (left.stroka == right.stroka)
        return true;
    return false;
}


char& Decoder::operator[] (const int index) // перегрузка []
{
    return stroka[index];
}

Decoder Decoder::base32Decode(string data) // Декодирование
{
    vector<unsigned char> Decode;

    data.erase(remove(data.begin(), data.end(), base32alphabet[32]), data.end()); // Убираем =

    int dataDlina = data.size();
    vector<char> bytes(data.begin(), data.end());
    int dVector = bytes.size();

    for (int bitIndex = 0; bitIndex < dataDlina * b32key; bitIndex += 8) {

        int dualbyte = (int)base32alphabet.find(bytes[bitIndex / b32key]) << 10; // ищем индекс символа в алфавите (ищем по 3)

        if (bitIndex / b32key + 1 < dVector) {
            dualbyte |= (int)base32alphabet.find(bytes[bitIndex / b32key + 1]) << b32key;
        }
        if (bitIndex / b32key + 2 < dVector) {
            dualbyte |= (int)base32alphabet.find(bytes[bitIndex / b32key + 2]);
        }

        dualbyte = 0xff & (dualbyte >> (15 - bitIndex % b32key - 8)); // находим индекс числа в таблице "ASCII"

        Decode.push_back(static_cast<unsigned char>(dualbyte)); //переводим число в символ

    }

    const int dlina = Decode.size();
    Decoder resultDecode;
    resultDecode.stroka.resize(dlina);
    for (auto i = 0; i<dlina; i++) {
        resultDecode.stroka[i] = Decode.at(i);
    }
    resultDecode.stroka[dlina] = '\0';
    return resultDecode;
}
