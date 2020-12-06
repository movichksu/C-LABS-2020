#include "TString.h"

void TString::initNULLstr(unsigned char* str)
{
	int len = str[0];
	if (len > maxSize)
		throw "\n Слишком большой размер строки.\n";
	for (int i = 0; i < len; ++i)
		string[i] = '\0';
}


TString::TString()
{
	string = new unsigned char;
	string[0] = '\0';
}
TString::TString(unsigned char* str)
{
	int len = str[0];
	string = new unsigned char[len];
	string[0] = '\0';
	initNULLstr(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '\0') { string[0] = i; string[i] = '\0'; break; }
		string[i] = str[i];
	}
	
}
TString::TString(TString& str):TString(str.string){}
TString::~TString()
{
	delete[] string; 
	string = nullptr;
}
int TString::getLength()
{
	int length;
	length = this->string[0];
	return length;
}
int TString::countStrLength( unsigned char* str)
{
	int length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return length;
}

bool TString::searchSubstr(unsigned char*)
{

	return true;
}
void TString::removeSubstr(unsigned char*)
{

}
unsigned char* TString::insertSubstr(unsigned char* str)
{

	return str;
}
/*TString TString::operator+(unsigned char* str)
{
	int bothLength = this->string[0] + str[0];
	if (bothLength > maxSize)
		throw "\n Общий размер строк превышает максимальный допустимый размер.\n";
	unsigned char buffer[] = { '\0' };
	buffer[0] = bothLength;
	for (int i = 1; i < this->string[0] - 1; i++)
	{
		buffer[i] = this->string[i];
	}
	for (int i = 1, j = this->string[0] - 1; i < str[0] - 1; i++, j++)
	{
		buffer[j] = str[i];
	}
	return buffer;
}
TString TString::operator=(unsigned char* str)
{

}
*/
TString TString::operator+(TString& str)
{
	int bothLength = this->string[0]+str.string[0];
	if (bothLength > maxSize)
		throw "\n Общий размер строк превышает максимально допустимый.\n";
	unsigned char* buff = new unsigned char[bothLength];
	buff[0] = bothLength;
	for (int i = 1; i < this->string[0]; i++)
	{
		buff[i] = this->string[i];
	}
	for (int i = 1, j = this->string[0]; j < bothLength - 1; i++, j++)
	{
		buff[j] = str.string[i];
	}

    TString buffer = buff;

	return buffer;
}
TString TString::operator=(TString& str)
{
	delete string; string = nullptr;
	int len = str.string[0];
	this->string = new unsigned char[len];
	for (int i = 0; i < len; i++)
	{
		if (str.string[i] == '\0') { this->string[0] = i; this->string[i] = '\0'; break; }
		this->string[i] = str.string[i];
	}

	return *this;
}

ostream& operator << (ostream& out, TString& str) {
	int len = str.string[0];
	out << len;
	for (int i = 1; i < str.getLength(); i++) {
		out << str.string[i];
	}
	return out;
}
