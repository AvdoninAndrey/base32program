#include "Encoder.h"

ostream & operator<<(ostream &out, const Encoder &a) // перегрузка <<
{
    out << a.stroka;
    return out;
}

char& Encoder::operator[] (const int index) // перегрузка []
{
    return stroka[index];
}

Encoder::Encoder(const char * str)
{
    string result;
    int end;
    for (end = 0; str[end] != '\0'; end++); // узнаём длину
    result.resize(end+3); // выделяем размер строки
    for (int i=0; i<=end; i++) {
        result[i] = str[i];
        this->stroka[i] = result[i];
    }
}

bool operator ==(const Encoder & left, const Encoder & right)
{
    if (left.stroka== right.stroka)
        return true;
    return false;
}

vector<char> Encoder::B32bit_operations(unsigned long long int &buffer, int &bitCount) // Битовые операции в Base32
{
    vector <char> Encode;
    while (bitCount > 0) {
        auto index = bitCount >= b32key ?
                     static_cast<int>(buffer >> (bitCount - b32key)) & 0x1f : // "отщипываем по 5 бит"
                     static_cast<int>(buffer & static_cast<unsigned long long>(0x1f >> (b32key - bitCount))) << (b32key - bitCount);

        Encode.push_back(base32alphabet[index]); // переводим числа в символы алфавита, используя их, как индекс "массива"
        bitCount -= b32key;
    }
    return Encode;
}

vector<char> Encoder::Base_equally(vector<char> res) //= в Base32
{
    int dlinaEncoded = res.size();
    int padding = (8 - (dlinaEncoded % 8)) % 8;
    for (auto i = 0; i < padding; i++) {
        res.push_back(base32alphabet[32]); // добавляем =
    }
    return res;
}

Encoder Encoder::base32Encode(string data)
{
    vector <char> Encode, resbuffer;

    const int dataDlina = data.length(); // длина строки

    vector<unsigned char> perevod(dataDlina);

    for (auto i = 0; i < dataDlina; i++) {
        perevod.at(i)=data[i];        // переводим строку в вектор unsigned char
    }
    for (auto j = 0; j < dataDlina; j += b32key) {

        int byteCount = min(b32key, dataDlina - j); // учитываем возможность : (количества бит может быть  не кратно 5)
        unsigned long long int buffer = 0;

        for (auto i = 0; i < byteCount; i++) {
            buffer = (buffer << 8) | perevod.at(i + j); // помещаем наши байты
        }
        int BitCount = byteCount * 8;

        resbuffer = B32bit_operations(buffer, BitCount); // операции с битами в Base32

        for (int i = 0; i < resbuffer.size(); i++) {
            Encode.push_back(resbuffer.at(i));
        }
    }
    Encode = Base_equally(Encode); // добавляем =

    const int dlina = Encode.size();
    Encoder resultEncode;
    resultEncode.stroka.resize(dlina + 3);
    for (auto i = 0; i < dlina; i++) {
        resultEncode.stroka[i] = Encode.at(i);
    }
    resultEncode.stroka[dlina] = '\0';
    return resultEncode;
}
