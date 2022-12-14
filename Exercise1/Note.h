#pragma once
#include "Keeper.h"

class Note {
protected:
	string name;
	string surname;
	string phone_number;
	int data[3];
public:
	Note();
	Note(const Note& obj);
	~Note();

	Note& operator= (const Note& other);
	void redact(Note&);
	string sort(Note&);
	bool names(Note&, string);
	bool search(Note&, int);
	friend ostream& operator<<(ostream&, Note&);
	friend istream& operator>>(istream&, Note&);
	friend ofstream& operator<<(ofstream&, Note&);
	friend ifstream& operator>>(ifstream&, Note&);
};
