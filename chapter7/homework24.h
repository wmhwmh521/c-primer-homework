#pragma once

#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>

using namespace std;



class Screen {

public:
	typedef string::size_type pos;

	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht* wd, ' '){}
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht* wd, c) {}

	char get() const {
		return contents[cursor];
	}
	inline char get(pos ht, pos wd) const;  //ÖØÔØget
	Screen& move(pos r, pos c);

	//void some_member() const;


	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	//mutable size_t access_ctr = 0;
};

inline
Screen& Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}
char Screen :: get(pos r, pos c) const { //constÒâÎªÖ¸ÏòµÄ*thisÊÇ³£Á¿
	pos row = r * width;
	return contents[row + c];
}
/*
void Screen :: some_member() const {
	++access_ctr;
}
*/




#endif // !SCREEN_H
