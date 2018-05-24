#include "MyString.hpp"
#include <stdio.h>

MyString::MyString(const char* s){
	String = NULL;
	if(s == NULL) throw"NULL POINTER!";

	int s_size = strlen(s);

	String = new char[s_size];
	for(int i = 0 ; i < s_size ; i++){
		*(String + i) = *(s + i);
	}

	*(String + s_size) = '\0';
}

MyString::MyString(unsigned int str_size){
	String = NULL;

	if(str_size <= 0) throw"Index length is smaller than 0";

	String = new char[str_size];

	memset(String, NULL, str_size * sizeof(char));
}

MyString::MyString() {
	String = NULL;
}

