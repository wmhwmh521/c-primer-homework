#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	string isbn() const {    //const意为不改变this中的内容
		return this->bookNo;
	}
	Sales_data& combine(const Sales_data&); //声明函数
};

Sales_data& Sales_data::combine(const Sales_data& rhs) {  //重写函数
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream& read(istream& is, Sales_data& item) {
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}


ostream& print(ostream& os, Sales_data& item) {
	cout << item.bookNo << " " << item.units_sold << " "
		<< item.revenue;
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data temp = lhs;
	temp.combine(rhs);
	return temp;
}
