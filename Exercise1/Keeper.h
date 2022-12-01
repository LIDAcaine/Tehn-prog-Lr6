#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <algorithm>


using namespace std;
template <class T>
class Keeper {

	T* ptr_mas;
	int size;
public:
	Keeper() { size = 0; ptr_mas = nullptr;/* cout << "Object  Keeper created" << endl;*/ };
	~Keeper() { delete[] ptr_mas; /*cout << "Object Keeper deleted" << endl; */ };

	void save(string);
	void read(string);
	void add();
	void del(int index);
	void print();
	void redaction(int index);
	void sort_month();
	void sort_surname();
	void sort_fio();


};


template<class T>
void Keeper<T>::sort_month() {
	int month;
	int cnt = 0;
	cout << "Введите месяц>> ";
	cin >> month;
	if (size == 0)
		cout << "Записи отсутствуют." << endl;
	else {

		for (int i = 0; i < size; i++) {

			if (ptr_mas[i].search(ptr_mas[i], month))
			{
				cout << ptr_mas[i] << endl;
			}
			else {
				cnt++;
			}
		}
	}
	if (cnt == size)
	{
		cout << "Совпадений не найдено." << endl;
	}
}

template<class T>
void Keeper<T>::sort_surname() {
	string month;
	int cnt = 0;
	cout << "Введите фамилию>> ";
	cin >> month;
	if (size == 0)
		cout << "Записи отсутствуют." << endl;
	else {

		for (int i = 0; i < size; i++) {

			if (ptr_mas[i].names(ptr_mas[i], month))
			{
				cout << ptr_mas[i] << endl;
			}
			else {
				cnt++;
			}
		}
	}
	if (cnt == size)
	{
		cout << "Совпадений не найдено." << endl;
	}
}

template<class T>
void Keeper<T>::sort_fio() {

	if (size == 0) {
		cout << "Записи отсутствуют." << endl;
	}
	else {
		T tmp;
		for (int i = 0; i < size; i++) {
			for (int j = (size - 1); j >= (i + 1); j--) {
				if (ptr_mas[j].sort(ptr_mas[j]) < ptr_mas[j - 1].sort(ptr_mas[j - 1])) {
					tmp = ptr_mas[j];
					ptr_mas[j] = ptr_mas[j - 1];
					ptr_mas[j - 1] = tmp;
				}
			}
		}
	}

}

template<class T>
void Keeper<T>::redaction(int index) {

	if (size == 0)
		cout << "Записи отсутствуют." << endl;
	else {

		try {

			if (index-1 > size - 1 || index-1 < 0)
				throw exception("Некорректный ввод данных.");
		}
		catch (exception& ex) {
			while (index-1 < 0 || index-1 > size - 1) {
				cout << ex.what() << endl;
				cout << "Введите индекс ещё раз>> ";
				cin >> index;
			}
		}


		T* tmp = new T[size];
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (i != index-1) {
				tmp[j++] = ptr_mas[i];
			}
			else {
				cout << "Редактируемая запись" << endl;
				cout << ptr_mas[i] << endl;
				ptr_mas[i].redact(ptr_mas[i]);
				cout << "Запись отредактирована." << endl;
			}
		}

		//cout << "Запись отредактирована." << endl;
	}
}

template<class T>
void Keeper<T>::save(string s) {
	ofstream fout(s, ios::out);

	try {
		if (size == 0)
			throw exception("Записи отсутствуют.");

		fout << size << endl;
		for (int i = 0; i < size; i++) {
			fout << ptr_mas[i] << endl;
		}
		cout << "Данные успешно сохранены." << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	fout.close();
}

template<class T>
void Keeper<T>::read(string s) {
	ifstream fin(s, ios::in);

	fin >> size;

	if (ptr_mas != nullptr)
		delete[] ptr_mas;

	ptr_mas = new T[size];

	for (int i = 0; i < size; i++) {
		fin >> ptr_mas[i];
	}

	cout << "Данные успешно считаны." << endl;
	fin.close();
}



template<class T>
void Keeper<T>::add() {
	T* tmp = new T[size + 1];
	for (int i = 0; i < size; i++) {
		tmp[i] = ptr_mas[i];
	}
	delete[] ptr_mas;
	cin >> tmp[size];
	ptr_mas = tmp;
	size++;
}

template<class T>
void Keeper<T>::del(int index) {
	if (size == 0)
		cout << "Записи отсуствуют." << endl;
	else {

		try {

			if (index-1 > size - 1 || index-1 < 0)
				throw exception("Некорректный ввод данных.");
		}
		catch (exception& ex) {
			while (index-1 < 0 || index-1 > size - 1) {
				cout << ex.what() << endl;
				cout << "Введите индекс ещё раз>> ";
				cin >> index;
			}
		}

		T* tmp = new T[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (i != index-1)
				tmp[j++] = ptr_mas[i];
		}
		delete[] ptr_mas;
		ptr_mas = tmp;
		size--;
		cout << "Запись удалена." << endl;
	}
}

template<class T>
void Keeper<T>::print() {
	sort_fio();
	if (size == 0)
		cout << "Записи отсутствуют." << endl;
	else
		for (int i = 0; i < size; i++) {
			cout << "["<<i+1<<"]" << endl;
			cout << ptr_mas[i] << endl;
		}
}
