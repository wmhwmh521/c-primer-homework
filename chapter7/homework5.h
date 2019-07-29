#pragma once
#include <string>

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
