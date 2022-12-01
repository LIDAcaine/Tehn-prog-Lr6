#include "Note.h"
#include "Keeper.h"

Note::Note() {
	//cout << " The default constructor of the class was called Note" << endl;
	name = "������ ����������";
	surname = "������ ����������";
	phone_number = "������ ����������";
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
	out << "������� � ���: " <<obj.surname << " " << obj.name << endl;
	out << "����� ��������: " << obj.phone_number << endl;
	out << "���� ��������: " << obj.data[0] << ".";
	out << obj.data[1] << ".";
	out << obj.data[2] << endl;
	return out;

}

istream& operator>>(istream& in, Note& obj) {
	cout << "������� ���: ";
	getchar();
	getline(in, obj.name);

	cout << "������� �������: ";
	getline(in, obj.surname);

	cout << "������� ����� ��������: ";
	getline(in, obj.phone_number);

	cout << "������� ���� ��������: ";
	while (!(in >> obj.data[0]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //���������� ���� ������, ���� ������� ����
		in.ignore(1000, '\n'); //���������� ���������� � ������ ������
		cout << "������������ ���� ������, ��������� �������: ";
	}

	cout << "������� ����� ��������: ";
	while (!(in >> obj.data[1]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //���������� ���� ������, ���� ������� ����
		in.ignore(1000, '\n'); //���������� ���������� � ������ ������
		cout << "������������ ���� ������, ��������� �������: ";
	}
	cout << "������� ��� ��������: ";
	while (!(in >> obj.data[2]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //���������� ���� ������, ���� ������� ����
		in.ignore(1000, '\n'); //���������� ���������� � ������ ������
		cout << "������������ ���� ������, ��������� �������: ";
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
	cout << "��������������: " << endl<< "1 - ���" <<endl 
		<< "2 - �������" << endl << "3 - ����� ��������" 
		<< endl << "4 - ���� ��������" << endl << "5 - ������"<< endl;
	cin >> index;
	switch (index)
	{
	case 1:
		cout << "������� ����� ���: ";
		getchar();
		getline(cin, obj.name);
		break;
	case 2:
		cout << "������� ����� �������: ";
		cin >> obj.surname;
		break;
	case 3:
		cout << "������� ����� ����� ��������: ";
		cin >> obj.phone_number;
		break;
	case 4:
		cout << "������� ����� ���� ��������: ";
		cin >> obj.data[0];
		cout << "������� ����� ����� ��������: ";
		cin >> obj.data[1];
		cout << "������� ����� ��� ��������: ";
		cin >> obj.data[2];
		break;
	default:
		break;
	}

}
