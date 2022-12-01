#include <Windows.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Keeper.h"
#include "Note.h"
#include "Menu.h"
#define ERROR_101 101
#define ERROR_102 102
using namespace std;

int main() {

	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "Rus");
	Keeper<Note> obj;
	system("cls");
	Menu(obj, "phone_number.txt");
    return 0;
}

