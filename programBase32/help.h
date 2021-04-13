#pragma once
#include <string>
#include <iostream>
using namespace std;
class Help
{
private :
    const string h = "Справка о режимах работы:\n"
                     "Encode - кодирование данных в Base32.\n"
                     "Decode - декодирование данных из Base32.\n"
                     "exit - завершить работу программы.\n";
public:
    void printHelp();
};
