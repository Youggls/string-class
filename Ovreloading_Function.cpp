#include "MyString.hpp"
#include <iostream>
using std::ostream;
using std::istream;


const MyString MyString::operator+(const MyString& right) {
	if (right.String == NULL) 
		throw"The right value has not been initialized!";
	
	int rv_sz = length() + right.length();
	MyString rv;
	rv.String = new char[rv_sz];

	for (int i = 0; i < rv_sz; i++) {
		if (i < length()) rv.String[i] = *(String + i);
		else *(rv.String + i) = *(right.String + i - length());
	}

	*(rv.String + rv_sz) = '\0';

	return rv;
}

MyString& MyString::operator=(const MyString src) {
	if (src.String == NULL) 
		throw"The source string has not been initialized1";

	delete[] String;
	String = new char[src.length() + 1];
	for (int i = 0; i < src.length(); i++) {
		*(String + i) = *(src.String + i);
	}
	*(String + src.length()) = '\0';

	return *this;
}

MyString& MyString::operator=(const char* s) {
	delete[] String;
	String = new char[strlen(s) + 1];

	for (int i = 0; i < strlen(s); i++) {
		*(String + i) = *(s + i);
	}
	*(String + strlen(s)) = '\0';

	return *this;
}

bool MyString::operator==(const MyString& judgement) {
	if (judgement.String == NULL) throw"The right value has not been initialized!";

	if (length() != judgement.length()) return false;
	bool flag = true;
	for (int i = 0; i < length(); i++) {
		if (*(String + i) != *(judgement.String + i)) {
			flag = false;
			break;
		}
	}

	return flag;
}

char MyString::operator[](int site) {
	return *(String + site);
}

ostream& operator<<(ostream& os, const MyString& ou) {
	if (ou.String == NULL) throw"The String has not been initialized!";

	os << ou.String;
	return os;
}

istream& operator>>(istream& is, MyString& in) {
	delete[] in.String;
	in.String = NULL;
	in.String = new char[2048];

	is >> in.String;

	return is;
}