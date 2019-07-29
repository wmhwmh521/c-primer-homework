#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	string isbn() const {    //const��Ϊ���ı�this�е�����
		return this->bookNo;
	}
	Sales_data& combine(const Sales_data&); //��������
	istream& read(istream& is, Sales_data& item);
	ostream& print(ostream& os, Sales_data& item);
	Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
};

Sales_data& Sales_data::combine(const Sales_data& rhs) {  //��д����
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream& Sales_data::read(istream& is, Sales_data& item) {
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}


ostream& Sales_data :: print(ostream& os, Sales_data& item) {
	cout << item.bookNo << " " << item.units_sold << " "
		<< item.revenue;
	return os;
}

Sales_data Sales_data::add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data temp = lhs;
	temp.combine(rhs);
	return temp;
}