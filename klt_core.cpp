/****************************************************************************************
*    KLT : A terminal tool that help you learn kana                                     *
*    Copyright KLT (C) 2018 - 2019  Antoine Braut                                       *
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

#include "klt_core.hpp"

klt_core::klt_core() //: trainer(dic)
{
	//trainer=Kana_trainer(dic);
	core=true;
	inp=0;
	invalid_choice=false;

	menu_string = std::vector<string> ({"Welcome in Kana Learning Tool - ようこそ",
																			"1 - Go for some random kana",
																			"2 - Show Kana Table",
																			"3 - Try some words (WIP)",
																			"4 - Quit and come back later"});
	highlight=1;
	choice=0;

}

klt_core::~klt_core()
{

}

int klt_core::start_loop()
{
	menu_win = newwin(8,35,5,10);
	int c;

	keypad(menu_win, TRUE);

	mvprintw(0,4,"%s",menu_string.at(0).c_str());
	refresh();

	nc_print_menu(menu_win, highlight);

	while(core)
	{
		if(choice)
		{
			mvprintw(0,4,"%s",menu_string.at(0).c_str());
			refresh();

			nc_print_menu(menu_win, highlight);

			choice=0;
		}


		c = wgetch(menu_win);

		switch (c)
		{
			case KEY_UP:
					if(highlight == 1)
						highlight = menu_string.size()-1;
					else
						--highlight;
					break;
				case KEY_DOWN:
					if(highlight == menu_string.size()-1)
						highlight = 1;
					else
						++highlight;
					break;
				case 10:																																// Enter key
					choice = highlight;
					break;
		}

		switch(choice)
		{
			case 1 :
				start_random_kana();
				break;
			case 2 :
				print_table();
				break;
			case 3 :
				// todo
				break;
			case 4 :
				core=false;
				break;
		}

		nc_print_menu(menu_win, highlight);
	}

	return 0;
}

void klt_core::print_table()
{
	clear();

	dic.print_tab();
	dic.print_kat();
	mvprintw(22,0,"Press q to quit");
	refresh();

	while(getch()!='q');

	clear();
	choice=-1;
}

void klt_core::start_random_kana()
{
	Kana_trainer trainer(dic);

	clear();

	/* Config */
	trainer.configure_random_kana();

	/*   loop   */
	trainer.loop_random_kana();

	/* End function clear */
	cbreak();
	noecho();
	clear();
	choice=-1;
}

void klt_core::nc_print_menu(WINDOW *menu_win,int highlight)										// From the ncurses programmins howto
{																																								// http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/keys.html
	int y (2);
	box(menu_win,0,0);
	for (int i=0; i < menu_string.size()-1 ;i++)
	{
		if (highlight == i+1)
		{
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win,y,2,"%s",menu_string.at(i+1).c_str());
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win,y,2,"%s",menu_string.at(i+1).c_str());
		y++;
	}
	wrefresh(menu_win);
}
