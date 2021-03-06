/**
* @file Decoder.h
* @author Авдонин А.Д.
* @version 1.0
* @brief Описание класса Decoder
* @date 03.05.2021
* @copyright ИБСТ ПГУ
*/
#pragma once
#include "Alphabet.h"
#include <vector>
#include <algorithm>
///@brief Декодирует любые данные из Base32
class Decoder: protected Alphabets
{
private:
    ///@brief Ключ Base32
    ///@details Ключ Base32 равен 5, так как при Base32 используется набор из 32 символов, каждый из которых может быть представлен 5 битами.
    const int b32key = 5;
    ///@brief Хранит результат декодирования, а также предназначен для конструктора строкой.
    string stroka;
public:
    /**@brief перегрузка оператора []
    * @param index - целочисленное число
    * @return ссылку на тип "char", то есть по индеку в строке возвращает символ.
    * */
    char& operator[] (const int index); 
    ///@brief Конструктор по умолчанию
    Decoder () = default;
    ///@brief Деструктор по умолчанию
    ~Decoder () = default;
     /**@brief Конструктор строкой
     * @param std::string str - строка Си++
     * @details <p>Узнаём размер строки, которая пришла на вход. Меняем размер атрибута "stroka" для того, чтобы не было ошибок с памятью.
     *  Далее в данный private атрибут "stroka" записываем строку, которая пришла на вход.</p> <br>
     * @code
        int size_str= str.size();
        this->stroka.resize(size_str);
        this->stroka = str;
     * @endcode
     */
    Decoder(const string str);
    /**@brief Декодирование данных из Base32
     * @param std::string data - строка Си++
     * @details <p>В первую очередь, из строки, которая пришла на вход, удалаются символы "=", так как при декодировании их просто отбрасывают.</p> <br>
     *  @code
       data.erase(remove(data.begin(), data.end(), base32alphabet[32]), data.end()); // Убираем =
     *  @endcode
     * <p>Затем создаётся vector <char> с именем "bytes", в который записывается строка, пришедшая на вход.
     * После этого запускается цикл, в котором ищется индекс символа кодированной строки из алфвавита Base32. Далее данный индекс (число), которое нашлось, 
     * увеличивается в 1024 раз(то есть 2 в степени 10) и записывается в пременную типа int с именем "dualbyte".  <br>
     *  @code
       int dualbyte = (int)base32alphabet.find(bytes[bitIndex / b32key]) << 10;
     *  @endcode
     * Затем ищется последующий символ (точнее его индекс в алфавите Base32) в кодированной строке. И этот индекс (число) увеличивается уже в 32 раза(то есть 2 в степени 5). И далее 
     * осуществляется побитовая операция "|" с числом, которое уже хранится в переменной с именем "dualbyte". <br> 
     *  @code
        dualbyte |= (int)base32alphabet.find(bytes[bitIndex / b32key + 1]) << 5;
     *  @endcode
     * Затем ещё раз ищется последующий символ в кодированной строке (точнее его индекс в алфавите Base32) и это найденное число
     * также осуществляет побитовую операция "|" с числом, которое уже хранится в переменной с именем "dualbyte".</p> <br>
     *  @code
         dualbyte |= (int)base32alphabet.find(bytes[bitIndex / b32key + 2]);
     *  @endcode
     * <p>После этого находится код символа в таблице "Utf-8", так как программа использует именно эту кодировку. <br>
     *  @code
        dualbyte = 0xff & (dualbyte >> (15 - bitIndex % b32key - 8)); // находим код символа в таблице 
     *  @endcode
     * Затем код символа переводится в символ и записывается vector<unsigned char> с именем "Decode".</p> <br>
     *  @code
        Decode.push_back(static_cast<unsigned char>(dualbyte)); //переводим число в символ 
     *  @endcode
     * <p>После выхода из цикла в атрибут класса "Decoder" c именем "stroka" записывается содержимое вектора, в котором хранятся символы декодированной строки.</p>
     * <p>Важно сказать, что поиск осуществляется именно по три символа, потому что Base32 составляет 160 процентов от объёма обычных данных. Причём поиск не 
     * осущетсвляется по новым трём символам. То есть, если кодированная строка имела вид - "ABCDEFGH", то при первом проходе цикла найдутся символы
     * "ABC", а при втором проходе найдутся cимволы "BCD" и так далее.
     * Но если у строки, которая пришла на вход количество символов, умноженное на ключ Base32, не кратно 8 битам, то поиск может находить только один или два символа. Именно поэтому в цикле второй и третий поиск 
     * осуществляются только в том случае, если выполнено определённое условие, которое проверяет строку на кратность 8 битам.</p>
     *@return Декодировання строка типа "Decoder".
     */
    Decoder base32Decode(string data); // декодирование
    /**@brief Перугрзка оператора сравнение "==".
     * @param left - ссылка на левый операнд типа "Decoder".
     * @param right - ссылка на правый операнд типа "Decoder".
     * @details С помощью обычного условия сравнивается private атрибут "stroka" у обоих операндов. <br>
     *  @code
         if (left.stroka== right.stroka) {}
     *  @endcode
     * @return значение "true", если условие выполнено успешно, и значение "false" в противном случае.
     */
    friend bool operator ==(const Decoder & left, const Decoder & right);
    /**@brief Перугрзка оператора побитового сдвига "<<" для вывода.
    * @param out - ссылка на операнд типа "ostream".
    * @param a - ссылка на операнд типа "Decoder".
    * @details  Внутри функции "operator<<" происходит вывод строки, на которую указывает атрибут "a" нашего класса "Decoder",
    * в поток, задаваемый параметром "out".
    * @return ссылочный тип "ostream" на поток вывода.
    */
    friend ostream & operator<<(ostream &out, const Decoder &a);
   
};
