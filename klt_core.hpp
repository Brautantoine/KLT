/****************************************************************************************
*    KLT : A terminal tool that help you learn kana                                     *
*    Copyright KLT (C) 2018 -2019  Antoine Braut                                        *
*                                                                                       *
*    This program is free software: you can redistribute it and/or modify               *
*    it under the terms of the GNU General Public License as published by               *
*    the Free Software Foundation, either version 3 of the License, or                  *
*    (at your option) any later version.                                                *
*                                                                                       *
*    This program is distributed in the hope that it will be useful,                    *
*    but WITHOUT ANY WARRANTY; without even the implied warranty of                     *
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                      *
*    GNU General Public License for more details.                                       *
*                                                                                       *
*    You should have received a copy of the GNU General Public License                  *
*    along with this program. If not, see <https://www.gnu.org/licenses/>.              *
*                                                                                       *
*    Contact : Antoine.braut@gmail.com                                                  *
*                                                                                       *
****************************************************************************************/

#ifndef KLT_CORE
#define KLT_CORE

#include "kana.hpp"
#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <cstdlib>
#include <exception>

class klt_core
{
	public:
	klt_core();
	~klt_core();
	int start_loop();

	private:

	void print_table();
	void start_random_kana();
	void nc_print_menu(WINDOW* menu_win,int highlight);

	bool core;
	int inp;
	kana_dic dic;
	bool invalid_choice;
	std::vector<string> menu_string;

	//ncurses attribute
	WINDOW *menu_win;
	int highlight;
	int choice;
};

#endif //KLT_CORE
