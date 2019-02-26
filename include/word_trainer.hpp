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

#ifndef WORD_TRAINER_HPP
#define WORD_TRAINER_HPP

//#include "kana.hpp"
//#include <iostream>
#include "dic_conteneur.hpp"
#include "manifest_conteneur.hpp"
#include <unistd.h>
#include <ncurses.h>
#include <cstdlib>
#include <exception>

class word_trainer{

  public:

  word_trainer(dic_conteneur& n_dic);
  virtual ~word_trainer();

  void configure_random_word();
	void loop_random_word();

  private :

  /*void nc_print_table_config();
  void nc_print_kana_config();
  void nc_print_row_config();*/

  //void nc_print_dic_config();

  //int inp;
  //kana_dic dic;
  dic_conteneur dic;
  std::vector<std::string> config_string;

  //configurable attribute
  enum{hiragana,katakana,both} kana_choice;

  //NCURSES attribute
  WINDOW *config_win;
  int highlight;
  int choice;
};

#endif // WORD_TRAINER_HPP
