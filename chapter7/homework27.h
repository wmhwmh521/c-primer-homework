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
	Screen& set(char);
	Screen& set(pos, pos, char);
	Screen& display(ostream& os);
	const Screen& display(ostream& os) const;


	//void some_member() const;

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	void do_display(ostream& os) const {
		os << contents;
	}
	//mutable size_t access_ctr = 0;
};

inline Screen& Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}
inline char Screen :: get(pos r, pos c) const { //constÒâÎªÖ¸ÏòµÄ*thisÊÇ³£Á¿
	pos row = r * width;
	return contents[row + c];
}

inline Screen& Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}
inline Screen& Screen::set(pos r , pos col, char ch) {
	contents[r * width + col] = ch;
	return *this;
}
inline Screen& Screen::display(ostream& os) {
	do_display(os);
	return *this;
}
inline const Screen& Screen::display(ostream& os) const {
	do_display(os);
	return *this;
}
/*
void Screen :: some_member() const {
	++access_ctr;
}
*/




#endif // !SCREEN_H
