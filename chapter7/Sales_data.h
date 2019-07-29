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
};

Sales_data& Sales_data::combine(const Sales_data& rhs) {  //��д����
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}