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
}

klt_core::~klt_core()
{

}

int klt_core::start_loop()
{
	while(core)
	{
		system("clear");
		std::cout << "\n\t\tWelcome to KLT\n\n\t1 - Go for some random kana\n\t2 - Show Kana Table\n\t3 - Quit and come back later\n\n\tYour choice : " ;
		if(invalid_choice)
			std::cout << "[Your choice is in another castle] : ";

		std::cin.sync();
		std::cin >> inp;

		switch(inp)
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
			default :
				invalid_choice=true;
		}
	}

	return 0;
}

void klt_core::print_table()
{
	char c(0);
	invalid_choice=false;
	system("clear");
	dic.print_tab();
	std::cout << std::endl <<  "Enter q to quit";
	while(c!='q')std::cin.get(c);
}

void klt_core::start_random_kana()
{
	bool core2(true);
	string input; // String and using string declare in kana.hpp
	int nb_row(10);

	system("clear");

	std::cout<<"How many row do you want ? : ";

	std::cin>>nb_row;

	if(nb_row<=0 || nb_row>10)
		nb_row=10;

	while(core2)
	{
		system("clear");

		dic.draw_kana(nb_row);
		dic.print_tab(nb_row);
		std::cout << "Wich Romaji correspond to the kana ";
		dic.print_current();
		std::cout << " : ";

		std::cin >> input;

		if(dic.compare_kana(input))
		{
			std::cout<<std::endl<<"Correct ";
			dic.print_current();std::cout << " -> ";
			dic.print_current_romaj();std::cout << " !" << std::endl;
		}
		else
		{
			std::cout<<std::endl<<"Wrong ";
			dic.print_current();
			std::cout << " -> ";
			dic.print_current_romaj();
			std::cout << " !" << std::endl;
		}
		std::cout << "Continue ? (Y/N) : ";

		std::cin >> input;

		if (input == "N" || input == "n")
			core2=false;
	}
}
