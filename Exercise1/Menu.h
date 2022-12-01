#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include "Keeper.h"
#include "Note.h"

template <typename T>
void Menu(T& obj, string s) {
	int menu;
	int index;
	string name;
	int flag = 1;
	while (flag) {
		system("cls");
		cout << "Задание №1: Телефонная книга" << endl;
		cout << "   1 - Добавить запись" << endl;
		cout << "   2 - Удалить запись" << endl;
		cout << "   3 - Читать из файла" << endl;
		cout << "   4 - Сохранить в файл" << endl;
		cout << "   5 - Вывести все записи" << endl;
		cout << "   6 - Редактировать запись" << endl;
		cout << "   7 - Поиск по месяцу рождения" << endl;
		cout << "   8 - Поиск по фамилии" << endl;
		cout << "   0 - Завершение работы" << endl;

		cout << ">> ";
		cin >> menu;
		switch (menu) {
		case 1:
			obj.add();
			break;
		case 2:
			obj.print();
			cout << "Введите номер записи>> ";
			cin >> index;
			obj.del(index);
			system("pause");
			break;
		case 3:
			obj.read(s);
			system("pause");
			break;
		case 4:
			obj.save(s);
			system("pause");
			break;
		case 5:
			obj.print();
			system("pause");
			break;
		case 6:
			obj.print();
			cout << "Введите номер записи>> ";
			cin >> index;
			obj.redaction(index);
			system("pause");
			break;
		case 7:
			obj.sort_month();
			system("pause");
			break;
		case 8:
			obj.sort_surname();
			system("pause");
			break;
		case 0:
			flag = 0;
			break;
		default:
			cout << "Ошибка! Некорректный ввод данных." << endl;
			system("pause"); 
			break;
		}
	}
}