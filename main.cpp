/****************************************************************************************
*    KLT : A terminal tool that help you learn kana                                     *
*    Copyright KLT (C) 2018  Antoine Braut                                              *
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

#include <iostream>
#include "kana.hpp"
#include <time.h>
#include <unistd.h>
#include "klt_core.hpp"
//#include <ncurses.h>

//#define NB_KANA 42

int main()
{

	klt_core main_loop;

	//initscr();
	main_loop.start_loop();

	/*printw("je suis la fenetre ncurses ... eh oui");
	getch();
	clear();
	std::cout << " et je marche avec un cout" << '\n';
	getch();
	clear();
	endwin();*/
	return 0;
}
