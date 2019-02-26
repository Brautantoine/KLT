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

#include "word_trainer.hpp"

word_trainer::word_trainer(dic_conteneur& n_dic) : dic(n_dic)
{

}

word_trainer::~word_trainer()
{

}

void word_trainer::configure_random_word()
{

}

void word_trainer::loop_random_word()
{
  nocbreak();
  echo();

  bool core (TRUE);
  char temp[10];
  std::string input;

  while(core)
  {
    clear();
    dic.draw_random_word();
    mvprintw(2,25,"What is the translation of : ");
    printw("%s : ",dic.get_current().c_str());
    refresh();

    getstr(temp);
		input = temp;

    if(dic.compare_word(input))
		{
			mvprintw(4,25,"Correct ");
			printw("%s ",dic.get_current().c_str());
			printw(" -> ");
      printw("%s ",dic.get_current_romaj().c_str());
			printw(" !");
			refresh();
		}
		else
		{
			mvprintw(4,25,"Wrong  ");
			printw("%s ",dic.get_current().c_str());
			printw(" -> ");
			printw("%s ",dic.get_current_romaj().c_str());
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
