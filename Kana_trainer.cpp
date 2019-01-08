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

#include "Kana_trainer.hpp"

Kana_trainer::Kana_trainer(kana_dic& n_dic)
{
  dic=n_dic;
}

Kana_trainer::~Kana_trainer()
{

}

void Kana_trainer::configure_random_kana()
{
  char temp[10];
  nb_row=10;                                                                    // Default value overide
  /* elder */ mvprintw(0,0,"How many row do you want ? : ");
	refresh();

  /* passing to echo mode */
  nocbreak();
	echo();
	getstr(temp);

  /* Get user nb_row */
  try
	{
		nb_row = std::stoi(temp);
	}
	catch (const std::exception& e)                                               // Try catch mechanism only to prevent crash from bad arg
	{
		// std::cerr << "/* error message */" << '\n';
	}
	if(nb_row<=0 || nb_row>10)                                                    // Saturation
		nb_row=10;

  // To do : kana_choice config
  // To do : show_table config
}

void Kana_trainer::loop_random_kana()
{
  bool core (TRUE);
  char temp[10];
  std::string input;

  while(core)
  {
    clear();

		dic.draw_kana(nb_row);

		dic.print_tab(nb_row);

		mvprintw(2,25,"Wich Romaji correspond to the kana ");
		dic.print_current();
		printw(" : ");
		refresh();

		getstr(temp);
		input = temp;

		if(dic.compare_kana(input))
		{
			mvprintw(4,25,"Correct ");
			dic.print_current();
			printw(" -> ");
			dic.print_current_romaj();
			printw(" !");
			refresh();
		}
		else
		{
			mvprintw(4,25,"Wrong  ");
			dic.print_current();
			printw(" -> ");
			dic.print_current_romaj();
			printw(" !");
			refresh();
		}

		cbreak();
		noecho();

		mvprintw(6,25,"Continue ? (Y/N)");
		refresh();

		input = getch();

		if (input == "N" || input == "n")
			core=false;

		nocbreak();
		echo();
  }
}
