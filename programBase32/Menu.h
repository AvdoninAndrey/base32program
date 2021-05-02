/**
* @file Menu.h
* @author Авдонин А.Д.
* @version 1.0
* @copyright ИБСТ ПГУ
*/
#pragma once
#include "help.h"
#include "Decoder.h"
#include "Encoder.h"
#include "ExceptionDecodeStroka.h"
#include "Result.h"
///@brief Взаимодействие пользователя с программой
class Menu
{
private:
    ///@brief Команда для декодирования данных из Base32.
    const string dec = "Decode";
    ///@brief Команда для кодирования данных в Base32.
    const string enc = "Encode";
    ///@brief Команда для отказа в получении справки.
    const string contin = "not";
    ///@brief Команда для завершения работы программы.
    const string ex = "exit";
    ///@brief Команда для вывода справки о режимах работы программы.
    const string spravka = "help";
public:
///@brief Взаимодействие с пользователем.
/**@details Предоставляет пользователю выбор в режиме работе (кодирование/декодирование), а также
 * предоставляет ввод обрабатываемых данных.
 * И при необходости выдаёт справку о работе программы.
 * */
    void Select();
};
