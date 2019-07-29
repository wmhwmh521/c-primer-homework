#ifndef SALES_DATA_H
#define SALES_DATA_H




#pragma once



#include <iostream>
#include <string>
#include "Sales_data.h"

using namespace std;

struct Sales_data;
istream& read(istream&, Sales_data&);    //声明非常重要不然会出错


struct Sales_data {
	//友元
	friend istream& read(istream& is, Sales_data& item);
	friend ostream& print(ostream& os, Sales_data& item);
	friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);


	Sales_data() = default;
	Sales_data(const string& s) :bookNo(s){}
	Sales_data(const string& s, unsigned n, double p) :bookNo(s), 
		units_sold(n), revenue(n * p) {}
	Sales_data(istream& is) {
		read(is, *this);                                   //调用read函数的时候read还没被定义，
																//	所以要先进行声明不然会出错
																//又因为read用了Sales_data类型所以要先声明Sales_data
	}

	string isbn() const {    //const意为不改变this中的内容
		return this->bookNo;
	}
	Sales_data& combine(const Sales_data&); //声明函数


private:
	//成员变量
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

};
//声明函数
istream& read(istream& is, Sales_data& item);
ostream& print(ostream& os, Sales_data& item);
Sales_data add(const Sales_data& lhs, const Sales_data& rhs);



Sales_data& Sales_data::combine(const Sales_data& rhs) {    //重写函数
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


#endif