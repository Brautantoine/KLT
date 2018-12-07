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

#include "klt_core.hpp"

klt_core::klt_core()
{
	core=true;
	inp=0;
	invalid_choice=false;

	menu_string = std::vector<string> ({"Welcome in Kana Learning Tool - ようこそ",
																			"1 - Go for some random kana",
																			"2 - Show Kana Table",
																			"3 - Quit and come back later"});
	highlight=1;
	choice=0;
}

klt_core::~klt_core()
{

}

int klt_core::start_loop()
{
	menu_win = newwin(7,35,5,10);
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

		//system("clear"); //before ncurses
		//clear(); // after ncurses
		//std::cout << "\n\t\tWelcome to KLT\n\n\t1 - Go for some random kana\n\t2 - Show Kana Table\n\t3 - Quit and come back later\n\n\tYour choice : " ; //before ncurses
		/*if(invalid_choice)
			std::cout << "[Your choice is in another castle] : ";*/

		/*std::cin.sync();
		std::cin >> inp;*/
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
				case 10:
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
				core=false;
				break;
		/*	default :
				invalid_choice=true; */
		}
		nc_print_menu(menu_win, highlight);
	}
	//clear();
	return 0;
}

void klt_core::print_table()
{
	//char c(0);
	//invalid_choice=false;
	//system("clear");
	clear();
	dic.print_tab();
	//std::cout << std::endl <<  "Enter q to quit";
	mvprintw(22,0,"Press q to quit");
	refresh();
	while(getch()!='q');
	clear();
	choice=-1;
}

void klt_core::start_random_kana()
{
	//bool core2(true);
	string input; // String and using string declare in kana.hpp
	char  temp[10];
	int nb_row(10);

	//system("clear");
	clear();

	//std::cout<<"How many row do you want ? : ";
	mvprintw(0,0,"How many row do you want ? : ");
	refresh();

	//std::cin>>nb_row;
	nocbreak();
	echo();
	getstr(temp);
	nb_row = std::stoi(temp);

	if(nb_row<=0 || nb_row>10)
		nb_row=10;

	while(1)
	{
		//system("clear");
		clear();

		dic.draw_kana(nb_row);
		dic.print_tab(nb_row);
		//std::cout << "Wich Romaji correspond to the kana ";
		mvprintw(2,25,"Wich Romaji correspond to the kana ");
		dic.print_current();
		//std::cout << " : ";
		printw(" : ");
		refresh();
		//std::cin >> input;
		getstr(temp);
		input = temp;

		if(dic.compare_kana(input))
		{
			//std::cout<<std::endl<<"Correct ";
			mvprintw(4,25,"Correct ");
			dic.print_current();
			//std::cout << " -> ";
			printw(" -> ");
			dic.print_current_romaj();
			//std::cout << " !" << std::endl;
			printw(" !");
			refresh();
		}
		else
		{
			//std::cout<<std::endl<<"Wrong ";
			mvprintw(4,25,"Wrong  ");
			dic.print_current();
			//std::cout << " -> ";
			printw(" -> ");
			dic.print_current_romaj();
			//std::cout << " !" << std::endl;
			printw(" !");
			refresh();
		}
		//std::cout << "Continue ? (Y/N) : ";
		cbreak();
		noecho();
		mvprintw(6,25,"Continue ? (Y/N)");
		refresh();

		//std::cin >> input;
		input = getch();

		if (input == "N" || input == "n")
			break;
		nocbreak();
		echo();
	}
	clear();
	choice=-1;
}

void klt_core::nc_print_menu(WINDOW *menu_win,int highlight)
{
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
