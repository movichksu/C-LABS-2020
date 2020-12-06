#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

class TString {
private:
	const unsigned maxSize = 255;
	unsigned char* string;
	void initNULLstr(unsigned char* );
	//int countStrLength(unsigned char* );
public:
	TString();
	TString( unsigned char* str);
	TString(TString&);
	~TString();
	int countStrLength(unsigned char*); // ?????????????????????
	int getLength(); // ???????????????????????
	unsigned char* getString() { return this->string; }
	bool searchSubstr(unsigned char* );
	void removeSubstr(unsigned char* );
	unsigned char* insertSubstr(unsigned char* );

	//TString operator+(unsigned char*);
	//TString operator=(unsigned char* );
	TString operator+(TString& );
	TString operator=(TString& );
	friend ostream& operator << (ostream&, TString&);


};
