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

word_trainer::word_trainer(std::vector<dic_conteneur>& n_vdic) : vdic(n_vdic), dic(vdic.at(0))
{
  //dic=vdic.at(1);
  config_win = newwin(10,50,5,10);
  highlight=0;
  offset=0;
}

word_trainer::~word_trainer()
{

}

void word_trainer::configure_random_word(manifest_conteneur& manifest)
{
  std::vector <std::string> dic_buffer;
  int c(0);
  bool loop(TRUE);
  choice=0;

  dic_buffer = manifest.get_names();

  keypad(config_win, TRUE);

  nc_print_dic_config(dic_buffer);

  while(loop)
	{

		c = wgetch(config_win);

		switch (c)
		{
			case KEY_UP:
					if(highlight+offset != 0)
          {
						//highlight = dic_buffer.size()-1;

            if(offset != 0)
              offset--;
            else
              highlight--;
          }
					/*else
						--highlight;*/
					break;
				case KEY_DOWN:
					if((unsigned int)(highlight+offset) != dic_buffer.size()-1)
						//highlight = 0;
          {
            if(highlight<4)
            {
              highlight++;
            }
            else
              offset++;
          }
					/*else
						++highlight;*/
					break;
				case 10:																																// Enter key
          dic=vdic.at(highlight+offset);
          loop=false;
					break;
		}
    wclear(config_win);
		nc_print_dic_config(dic_buffer);
	}
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
    mvprintw(2,5,"What is the translation of : ");
    printw("%s : ",dic.get_current().c_str());
    refresh();

    getstr(temp);
		input = temp;

    if(dic.compare_word(input))
		{
			mvprintw(4,5,"Correct ");
			printw("%s ",dic.get_current().c_str());
			printw(" -> ");
      printw("%s ",dic.get_current_romaj().c_str());
			printw(" !");
			refresh();
		}
		else
		{
			mvprintw(4,5,"Wrong  ");
			printw("%s ",dic.get_current().c_str());
			printw(" -> ");
			printw("%s ",dic.get_current_romaj().c_str());
			printw(" !");
			refresh();
		}

    mvprintw(10,0,"Detail : %s",dic.get_current_detail().c_str());
    
		cbreak();
		noecho();

		mvprintw(6,5,"Continue ? (Y/N)");
		refresh();

		input = getch();

		if (input == "N" || input == "n")
			core=false;

		nocbreak();
		echo();
  }
}

void word_trainer::nc_print_dic_config(std::vector<std::string>& dic_buffer)
{
  int y (3);
  int nbY = dic_buffer.size();
  if(nbY>5)
    nbY=5;
  mvwprintw(config_win,1,2,"Wich of these dictionnary do you want to use ?");
	box(config_win,0,0);
	for (int i=offset; i < nbY+offset ;i++)
	{
		if (highlight == i-offset)
		{
			wattron(config_win, A_REVERSE);
			mvwprintw(config_win,y,2,"%s",dic_buffer.at(i).c_str());
			wattroff(config_win, A_REVERSE);
		}
		else
			mvwprintw(config_win,y,2,"%s",dic_buffer.at(i).c_str());
		y++;
	}
	wrefresh(config_win);
}
