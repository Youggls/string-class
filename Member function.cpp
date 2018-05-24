#include "MyString.hpp"
#include <stdio.h>

inline const int MyString::length() const {
	if (String == NULL) {
		return -1;
		throw"The string has not been initialized!";
	}

	int rv_size = 0;
	for (int i = 0;; i++) {
		if (*(String + i) != '\0') rv_size++;
		else break;
	}

	return rv_size;
}

void MyString::Print() {
	if (String == NULL) 
		throw"The string has not been initialized!";

	for (int i = 0; i < length(); i++)
		printf("%c", *(String + i));
}

const MyString MyString::strc(const MyString& right) {
	if (right.String == NULL) throw"The right string has not been initialized!";

	int rv_sz = length() + right.length();
	MyString rv;
	delete[] rv.String;
	rv.String = new char[rv_sz + 1];
	for (int i = 0; i < rv_sz; i++) {
		if (i < length()) rv.String[i] = String[i];
		else rv.String[i] = right.String[i - length()];			//我也不知道为啥要加一个else 但是加上之后就没有bug了
	}

	rv.String[rv_sz] = '\0';
	
	return rv;
}

bool MyString::copy(MyString& dest, const MyString& src, int str_size) {
	if (src.String == NULL) throw"The source string has not been initialized!";
	if (str_size > src.length()) return false;

	delete[] dest.String;
	if (str_size = -1) {
		dest.String = new char[src.length() + 1];
		for (int i = 0; i < src.length(); i++) {
			*(dest.String + i) = *(src.String + i);
		}

		*(dest.String + src.length()) = '\0';
		return true;
	}
	else {
		dest.String = new char[str_size + 1];
		for (int i = 0; i < str_size; i++) {
			*(dest.String + i + 1) = *(src.String + i);
		}

		*(dest.String + str_size) = '\0';
		return true;
	}
}