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

#ifndef KANA_HPP
#define KANA_HPP

#include <vector>
#include <string>
#include <iostream>
#include <time.h>
#include <ncurses.h>

using std::string;

class kana_dic
{
	public :
	kana_dic();
	virtual ~kana_dic();
	string get_hirag(){return hirag_tab;}

	void print_tab(int row=10);
	void print_kana(int index);
	void print_romaj(int index);
	void print_current();
	void print_current_romaj();
	bool compare_kana(string input);
	void draw_kana(int nb_row=10);

	static const int NB_KANA;

	private :

	void init_tab();
	void emplace_romaj_tab();

	string hirag_tab;
	std::vector<string> hirag_tab_format;
	//string katak_tab; Not implemented yet
	std::vector<string> romaj_tab;
	int current_kana;

};



#endif // KANA_HPP
