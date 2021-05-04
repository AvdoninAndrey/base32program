/**
* @file Encoder.h
* @author Авдонин А.Д.
* @version 1.0
* @brief Описание класса Encoder
* @data 03.05.2021
* @copyright ИБСТ ПГУ
*/
#pragma once
#include "Alphabet.h"
#include <vector>
///@brief Кодирует любые данные в Base32
class Encoder: protected Alphabets
{
private:
///@brief Ключ Base32
///@details Ключ Base32 равен 5, так как при Base32 используется набор из 32 символов, каждый из которых может быть представлен 5 битами.
    const int b32key = 5;
///@brief Хранит результат кодирования, а также предназначен для конструктора строкой.
    string stroka;
    /**@brief Битовые операции в Base32.
     * @param buffer - представление символов в двоичном виде.
     * @param bitCount - количество бит в строке. Максимольное значение - 40 бит. Минимальное - 8 бит.
     * @details <p>Пока количество бит, которое пришло на вход функции не равно 0, происходит процесс "отщипления битов" по ключу Base32, который равен 5.</p>
     * <p>Если общее количество бит больше или равно 5, то "отщипление" проходит следующим образом:
     * полученное число после "отщипления" производит побитовую операцию "And" c числом 31, так как в алфавите Base32 - 32 основных символа.
     * Но побитовая операция "And" производится с числом 31, так как индексация в языке Cи++ начинается с 0.</p><br>
     *  @code
        static_cast<int>(buffer >> (bitCount - b32key)) & 0x1f;
     *  @endcode
     * Если же общее количество бит меньше 5, то "отщипление" проходит следующим образом:<br>
     *  @code
       static_cast<int>(buffer & static_cast<unsigned long long>(0x1f >> (b32key - bitCount))) << (b32key - bitCount);
     *  @endcode
     * <p>Полученные числа переводятся  в символы алфавита Base32.
     * Эти числа используются как индексы "массива" и записываются в vector <char>. </p><br>
     *  @code
       Encode.push_back(base32alphabet[index]);
     *  @endcode
     * Так как данный процесс находитя в цикле, то после каждой итерации, общее количество бит уменьшается на 5, то есть на ключ Base32.<br>
     *  @code
        bitCount -= b32key;
     *  @endcode
     * @return vector <char> с символами, которые являются основными символами Base32.
     * */
    vector<char> B32bit_operations(unsigned long long int &buffer, int &bitCount);
    /**@brief Добавление символа "=" в Base.
     * @param res - vector <char> с символами, которые являются основными символами Base32.
     * @details <p>Если при кодировании получась строка, у которой количество бит кратно 5, то символ "=" не добавляется.
     * В противном случае в строку добавляются "нулевые" биты до тех пор, пока общее число бит не станет делится на ключ Base32, который равен 5.
     * Тогда в кодированную строку добавляется символ "=" столько раз, сколько было добавлено так называемх "нулевых бит". </p>
     * <p>Количество добавления считается по слелующей формуле: <br>Count_EQUAL= (8 - (dlina % 8)) % 8,</br> где dlina - количество символов в кодированной строке. </p>
     * @return vector <char> с символами в формате Base32.
     * */
    vector<char> Base_equally (vector <char> res); // = в Base

public:
    /**@brief перегрузка оператора []
     * @param index - целочисленное число
     * @return ссылку на тип "char", то есть по индеку в строке возвращает символ.
      */
    char& operator[] (const int index);
    ///@brief Конструктор по умолчанию
    Encoder () = default;
    ///@brief Деструктор по умолчанию
    ~Encoder() = default;
    /**@brief Конструктор строкой
     * @param std::string str - строка Си++
     * @details <p>Узнаём размер строки, которая пришла на вход. Меняем размер атрибута "stroka" для того, чтобы не было ошибок с памятью.
     *  Далее в данный private атрибут "stroka" записываем строку, которая пришла на вход.</p><br>
     *  @code
        int size_str= str.size();
        this->stroka.resize(size_str);
        this->stroka = str;
     *  @endcode
     */
    Encoder (const string str);
    /**@brief Перугрзка оператора сравнение "==".
     * @param left - ссылка на левый операнд типа "Encoder".
     * @param right - ссылка на правый операнд типа "Encoder".
     * @details С помощью обычного условия сравнивается private атрибут "stroka" у обоих операндов.<br>
     * @code
       if (left.stroka == right.stroka) {};
     * @endcode
     * @return значение "true", если условие выполнено успешно, и значение "false" в противном случае.
      */
    friend bool operator == (const Encoder & left, const Encoder & right);
    /**@brief Кодирование любых данных в Base32.
     * @param std::string data - строка Си++, которую нужно закодировать.
     * @details <p>Узнаётся длина строки, которая пришла на вход. Далее создаётся vector <unsigned char> и в него записываются символы строки.
     * Это делается для того, чтобы метод мог кодировать строку, в которой присутствуют символы русского алфавита.</p><br>
     * @code
        vector<unsigned char> perevod(dataDlina);
        for (auto i = 0; i < dataDlina; i++) {
           perevod.at(i)=data[i];        // переводим строку в вектор unsigned char
        }
     * @endcode
     * <p>Затем в цикле каждые 5 байт( или же меньше в зависимости от размера строки, которая пришла на вход) строки переводятся в двоичный код и записываются
     * в переменную "buffer" типа "unsigned long long int".<br>
     * @code
       int byteCount = min(b32key, dataDlina - j); // учитываем возможность(количества бит может быть  не кратно 5)
       unsigned long long int buffer = 0;
     
        for (auto i = 0; i < byteCount; i++) {
           buffer = (buffer << 8) | perevod.at(i + j); // помещаем наши байты
       }
     * @endcode
     * Так как данный процесс происходит в цикле, то
     * в переменную "buffer" может записаться максимум - 40 бит, а минимум - 8.</p>
     * <p>Затем испольузется инкопсулированнай метод из "private" секции "B32bit_operations".<br>
     * @code
     *  resbuffer = B32bit_operations(buffer, BitCount); // операции с битами в Base32
     * @endcode
     * В итоге после выхода из цикла в vector-e <char> хранятся основные символы Base32 кодированной строки.
     * Затем к данному вектору пременяется  инкопсулированный метод из "private" секции "Base_equally", который добавляет в конец кодированной строки
     * символ "=" при необходимости.</p>
     * @code
     *  Encode = Base_equally(Encode);
     * @endcode
     * <p>Далее в атрибут класса "Encoder" c именем "stroka" записывается содержимое символьного вектора, в котором хранятся символы кодированной строки.</p>
     * @return Кодировання строка типа "Encoder"
     * */
    Encoder base32Encode(string data);
    /**@brief Перугрзка оператора побитового сдвига "<<" для вывода
    * @param out - ссылка на операнд типа "ostream".
    * @param a - ссылка на операнд типа "Encoder".
    * @details  <p>Внутри функции operator<< происходит вывод строки, на которую указывает атрибут "a" нашего класса "Encoder",
    *в поток, задаваемый параметром "out".</p>
    * @return ссылочный тип "ostream" на поток вывода.
    * */
    friend ostream & operator<<(ostream &out, const Encoder &a); // перегрузка <<
};
