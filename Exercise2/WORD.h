#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class WORD
{
private:
	string word;
public:
	void setword(string wrd);
	string getword() const;
	void change();
	friend ostream& operator <<(ostream& output, WORD& pointer);
};