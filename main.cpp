/****************************************************************************************
*    KLT : A terminal tool that help you learn kana                                     *
*    Copyright KLT (C) 2018 - 2019 Antoine Braut                                        *
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
#include <ncurses.h>
#include <locale.h>
#include "utils.hpp"



int main(int argc, char **argv)
{
	if(argc==1)
	{
		klt_core main_loop;

		setlocale(LC_ALL, "");
		initscr();
		clear();
		noecho();
		cbreak();
		main_loop.start_loop();

		clrtoeol();
		refresh();
		endwin();
	}
	else
	{
		for(int i=1;i<argc;i++)
		{
				switch (utils::arg_hash(argv[i]))
				{
					case 1:
						utils::show_help();
						return 0;
						break;
					case 2:
						utils::show_version();
						return 0;
						break;
					default:
						std::cout << "unknow argument : " << argv[i] << std::endl;
				}
		}
	}

	return 0;
}
