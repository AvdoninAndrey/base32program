/**
* @file help.h
* @author Авдонин А.Д.
* @version 1.0
* @brief Описание класса Help
* @date 03.05.2021
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <string>
#include <iostream>
using namespace std;
///@brief Справка о режимах работы программы
class Help
{
private :
    const string help = "Справка о режимах работы:\n Encode - кодирование данных в Base32.\n Decode - декодирование данных из Base32.\n exit - завершить работу программы.\n";
public:
///@brief Выводит справку о режимах работы программы, если она понадобится пользователю.
    void printHelp();
};
