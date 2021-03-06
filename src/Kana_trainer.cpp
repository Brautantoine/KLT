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
  //config_win = newwin(8,35,5,10);
  config_win = newwin(7,35,5,10);
  config_string = std::vector<std::string> ({"Do you want table to be shown ?",
                                           "Yes please I'm still learning",
                                           "No thanks I wanna practice",
                                           "Wich kana do you want ?",
                                           "Gimmeh Hiragana please",
                                           "Some Katakana please",
                                           "Both ! Both are good",
                                           "How many row do you want ?",
                                           "Something like : "});

  /* Default config value */
  show_table=true;
  kana_choice=hiragana;
  nb_row=10;
  highlight=1;
  offset_question=25;
}

Kana_trainer::~Kana_trainer()
{

}

void Kana_trainer::configure_random_kana()
{
  //char temp[10];
  //nb_row=10;
  int c(0);
  bool loop(TRUE);
  choice=0;

  keypad(config_win, TRUE);

  /* Display table config */
  nc_print_table_config();
  while(loop)
	{

		c = wgetch(config_win);

		switch (c)
		{
			case KEY_UP:
					if(highlight == 1)
						highlight = 2;
					else
						--highlight;
					break;
				case KEY_DOWN:
					if(highlight == 2)
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
				show_table=TRUE;
        loop=false;
				break;
			case 2 :
				show_table=false;
        loop=false;
				break;
		}

		nc_print_table_config();
	}

  loop=true;
  wclear(config_win);
  choice=0;
  highlight=1;
  wresize(config_win,8,35);

  /* Kana selection config */
  nc_print_kana_config();
  while(loop)
	{

		c = wgetch(config_win);

		switch (c)
		{
			case KEY_UP:
					if(highlight == 1)
						highlight = 3;
					else
						--highlight;
					break;
				case KEY_DOWN:
					if(highlight == 3)
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
				kana_choice=hiragana;
        dic.set_kana_type(kana_dic::HIRAGANA);
        loop=false;
				break;
			case 2 :
				kana_choice=katakana;
        dic.set_kana_type(kana_dic::KATAKANA);
        loop=false;
				break;
      case 3 :
  			kana_choice=both;
        loop=false;
      	break;
		}

		nc_print_kana_config();
	}

  nc_print_row_config();
}

void Kana_trainer::loop_random_kana()
{
  bool core (TRUE);
  char temp[10];
  std::string input;

  while(core)
  {
    clear();

    if(kana_choice==both)
		  dic.draw_both_kana(nb_row);
    else
      dic.draw_kana(nb_row);

		if(show_table)
    {
      switch (kana_choice) {
        case hiragana:
          dic.print_tab(nb_row);
          break;
        case katakana:
          dic.print_kat(nb_row,0);
          break;
        case both:
          if(dic.get_kana_type())
            dic.print_tab(nb_row);
          else
            dic.print_kat(nb_row,0);
          break;
      }
    }


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

void Kana_trainer::nc_print_table_config()
{
  int y (3);
	box(config_win,0,0);
  mvwprintw(config_win,1,2,"%s",config_string.at(0).c_str());
	for (int i=1; i < 3 ;i++)
	{
		if (highlight == i)
		{
			wattron(config_win, A_REVERSE);
			mvwprintw(config_win,y,2,"%s",config_string.at(i).c_str());
			wattroff(config_win, A_REVERSE);
		}
		else
			mvwprintw(config_win,y,2,"%s",config_string.at(i).c_str());
		y++;
	}
	wrefresh(config_win);
}

void Kana_trainer::nc_print_kana_config()
{
  int y (3);
	box(config_win,0,0);
  mvwprintw(config_win,1,2,"%s",config_string.at(3).c_str());
	for (int i=4; i < 7 ;i++)
	{
		if (highlight == i-3)
		{
			wattron(config_win, A_REVERSE);
			mvwprintw(config_win,y,2,"%s",config_string.at(i).c_str());
			wattroff(config_win, A_REVERSE);
		}
		else
			mvwprintw(config_win,y,2,"%s",config_string.at(i).c_str());
		y++;
	}
	wrefresh(config_win);
}

void Kana_trainer::nc_print_row_config()
{
  char temp[10];
  wclear(config_win);
  wrefresh(config_win);
  wresize(config_win,5,35);
  box(config_win,0,0);

  mvwprintw(config_win,1,2,"%s",config_string.at(7).c_str());
  mvwprintw(config_win,3,2,"%s",config_string.at(8).c_str());
  wrefresh(config_win);

   /* passing to echo mode */
  nocbreak();
	echo();

	wgetstr(config_win,temp);

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
}
