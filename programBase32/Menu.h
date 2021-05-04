/**
* @file Menu.h
* @author Авдонин А.Д.
* @version 1.0
* @brief Описание класса Menu
* @data 03.05.2021
* @copyright ИБСТ ПГУ
*/
#pragma once
#include "help.h"
#include "Decoder.h"
#include "Encoder.h"
#include "ExceptionDecodeStroka.h"
#include "Result.h"
///@brief Взаимодействие пользователя с программой.
///@details Реализация пользовательского интерфейса за счёт текстового диалога с использованием команд.
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
/**@details Запускается цикл, внутри которого пользователь выбирает режим работы (то есть кодирование/декодирование или же завершение работы программы). 
 * Также пользователю предоставляются права на ввод обрабатываемых данных и получение справки о работе программы при необходимости.
  */
    void Select();
};
