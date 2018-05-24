#ifndef MY_STRING
#define MY_STRING

#include <cstring>
#include <iostream>
using std::ostream;
using std::istream;
using std::endl;

class MyString {
private:
	MyString(unsigned int str_size);
	char* String;
public:
	//Constructor Functions

	MyString(const char* ); 
        MyString();

	//Member Functions

	void Print();
	const MyString strc(const MyString& b);
	bool copy(MyString& dest, const MyString& src, int str_size = -1);
	const int length() const;

	//Overloading functions

	const MyString operator+(const MyString& right);
	MyString& operator=(const MyString src);
	MyString& operator=(const char* );
	bool operator==(const MyString& judement);
	char operator[](int site);

	//Overloading input stream and output stream

	friend ostream& operator<<(ostream& os, const MyString& ou);
	friend istream& operator>>(istream& is, MyString& in);
};


#endif
