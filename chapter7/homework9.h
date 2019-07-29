#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Person {
	string name;
	string adress;
	
	string return_name() const{
		return name;
	}

	string return_adress() const {
		return adress;
	}

};

istream& read(istream& is, Person person) {
	is >> person.name >> person.name;
	return is;
}

ostream& print(ostream& os, Person person) {
	os << person.name << person.name;
	return os;
}
