#ifndef PERSON_H
#define PERSON_H

#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Person;
istream& read(istream&, Person);


struct Person {
	Person() = default;
	Person(const string& s1, const string& s2) : name(s1), adress(s2){} //¹¹Ôìº¯Êý
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

istream& read(istream& is, Person person) {
	is >> person.name >> person.name;
	return is;
}

ostream& print(ostream& os, Person person) {
	os << person.name << person.name;
	return os;
}


#endif