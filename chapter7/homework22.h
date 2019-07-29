#ifndef PERSON_H
#define PERSON_H

#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Person;
istream& read(istream&, Person);


struct Person {
	//友元
	friend istream& read(istream& is, Person person);
	friend ostream& print(ostream& os, Person person);

	
	//构造函数
	Person() = default;
	Person(const string& s1, const string& s2) : name(s1), adress(s2){} //构造函数
	Person(istream& is) {
		read(is, *this);
	}


	string name;
	string adress;


	string return_name() const{
		return name;
	}

	string return_adress() const {
		return adress;
	}

};
//函数声明
istream& read(istream& is, Person person);
ostream& print(ostream& os, Person person);

istream& read(istream& is, Person person) {
	is >> person.name >> person.adress;
	return is;
}

ostream& print(ostream& os, Person person) {
	os << person.name << person.name;
	return os;
}


#endif
