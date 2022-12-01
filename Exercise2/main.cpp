#include "WORD.h"
#include <iostream>
#include <sstream>
#include <fstream>
#define ERROR_101 101
#define ERROR_102 102

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    stringstream ss;
    string str;
    string temp;
    WORD buff;
    ifstream fin;
    fin.open("test.txt");
    try
    {
        if (!fin.is_open())
            throw ERROR_101;
    }
    catch (int error)
    {
        cout << "Файла с таким именем не существует в директории!" << endl;
        return ERROR_101;
    }
    cout << "Задание №2: Работа с текстом" << endl;
    while (!fin.eof())
    {
        getline(fin, str);
        ss << str;
        while (ss >> temp)
        {
            buff.setword(temp);
            buff.change();
            cout << buff << " ";
        }
        cout << endl;
        ss.clear();
    }
    try
    {
        if (!fin.is_open())
            throw ERROR_102;
    }
    catch (int error)
    {
        cout << "Файл не может быть закрыт!" << endl;
        return ERROR_102;
    }
    fin.close();
    return 0;
}