#pragma once

#include <iostream>
#include <string>
#include "Sales_data.h"

using namespace std;

struct Sales_data;
istream& read(istream&, Sales_data&);    //�����ǳ���Ҫ��Ȼ�����


struct Sales_data {
	Sales_data() = default;
	Sales_data(const string& s) :bookNo(s){}
	Sales_data(const string& s, unsigned n, double p) :bookNo(s), 
		units_sold(n), revenue(n * p) {}
	Sales_data(istream& is) {
		read(is, *this);                                   //����read������ʱ��read��û�����壬
																//	����Ҫ�Ƚ���������Ȼ�����
																//����Ϊread����Sales_data��������Ҫ������Sales_data
	}

	//��Ա����
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	string isbn() const {    //const��Ϊ���ı�this�е�����
		return this->bookNo;
	}
	Sales_data& combine(const Sales_data&); //��������
};

Sales_data& Sales_data::combine(const Sales_data& rhs) {  //��д����
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

