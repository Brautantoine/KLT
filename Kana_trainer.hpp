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

#ifndef KANA_TRAINER_HPP
#define KANA_TRAINER_HPP

#include "kana.hpp"
//#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <cstdlib>
#include <exception>

class Kana_trainer{

  public:

  Kana_trainer(kana_dic& n_dic);
  virtual ~Kana_trainer();

  void configure_random_kana();
	void loop_random_kana();

  private :

  void nc_print_config();

  //int inp;
  kana_dic dic;
  std::vector<std::string> menu_string;

  //configurable attribute
  bool show_table;
  enum{hiragana,katakana,both} kana_choice;
  int nb_row;

  //NCURSES attribute
  WINDOW *config_win;
  int highlight;
  int choice;
};

#endif // KANA_TRAINER_HPP
