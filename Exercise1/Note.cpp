#include "Note.h"
#include "Keeper.h"

Note::Note() {
	//cout << " The default constructor of the class was called Note" << endl;
	name = "Данные недоступны";
	surname = "Данные недоступны";
	phone_number = "Данные недоступны";
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
}


Note::Note(const Note& obj) {
	*this = obj;
}

Note::~Note() {
	//cout << "The class destructor was called Note" << endl;
}

Note& Note::operator=(const Note& other) {
	this->name = other.name;
	this->surname = other.surname;
	this->data[0] = other.data[0];
	this->data[1] = other.data[1];
	this->data[2] = other.data[2];
	this->phone_number = other.phone_number;
	return *this;
}

ostream& operator<<(ostream& out, Note& obj) {
	out << "Фамилия и имя: " <<obj.surname << " " << obj.name << endl;
	out << "Номер телефона: " << obj.phone_number << endl;
	out << "Дата рождения: " << obj.data[0] << ".";
	out << obj.data[1] << ".";
	out << obj.data[2] << endl;
	return out;

}

istream& operator>>(istream& in, Note& obj) {
	cout << "Введите имя: ";
	getchar();
	getline(in, obj.name);

	cout << "Введите фамилию: ";
	getline(in, obj.surname);

	cout << "Введите номер телефона: ";
	getline(in, obj.phone_number);

	cout << "Введите день рождения: ";
	while (!(in >> obj.data[0]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Некорректный ввод данных, повторите попытку: ";
	}

	cout << "Введите месяц рождения: ";
	while (!(in >> obj.data[1]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Некорректный ввод данных, повторите попытку: ";
	}
	cout << "Введите год рождения: ";
	while (!(in >> obj.data[2]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Некорректный ввод данных, повторите попытку: ";
	}
	return in;
}

string Note::sort(Note& obj)
{
	string str = surname + name;
	return str;
}
bool Note::names(Note& obj,string month)
{
	return month == obj.surname;
}
bool Note::search(Note& obj, int month)
{
	return month == obj.data[1];
}

ofstream& operator<<(ofstream& fout, Note& obj) {
	fout << obj.name << endl;
	fout << obj.surname << endl;
	fout << obj.phone_number << endl;
	fout << obj.data[0] << endl;
	fout << obj.data[1] << endl;
	fout << obj.data[2] << endl;
	return fout;
}

ifstream& operator>>(ifstream& fin, Note& obj) {

	fin.get();
	getline(fin, obj.name);
	//fin.get();
	getline(fin, obj.surname);
	//fin.get();
	getline(fin, obj.phone_number);
	fin >> obj.data[0];
	fin >> obj.data[1];
	fin >> obj.data[2];
	fin.get();
	return fin;
}

void Note::redact(Note& obj)
{
	int index;
	cout << "Редактирование: " << endl<< "1 - Имя" <<endl 
		<< "2 - Фамилия" << endl << "3 - Номер телефона" 
		<< endl << "4 - Дата рождения" << endl << "5 - Отмена"<< endl;
	cin >> index;
	switch (index)
	{
	case 1:
		cout << "Введите новое имя: ";
		getchar();
		getline(cin, obj.name);
		break;
	case 2:
		cout << "Введите новую фамилию: ";
		cin >> obj.surname;
		break;
	case 3:
		cout << "Введите новый номер телефона: ";
		cin >> obj.phone_number;
		break;
	case 4:
		cout << "Введите новый день рождения: ";
		cin >> obj.data[0];
		cout << "Введите новый месяц рождения: ";
		cin >> obj.data[1];
		cout << "Введите новый год рождения: ";
		cin >> obj.data[2];
		break;
	default:
		break;
	}

}
