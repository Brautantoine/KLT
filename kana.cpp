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

#include "kana.hpp"


const int kana_dic::NB_KANA=42;

kana_dic::kana_dic()
{
	current_kana=0;
	init_tab();
	srand(time(NULL));
}

kana_dic::~kana_dic()
{

}

void kana_dic::init_tab()
{
	hirag_tab = string ("あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわ");
	/*romaj_tab = std::vector<string> ({"a","i","u","e","o",
					  "ka","ki","ku","ke","ko",
					  "sa","shi","su","se","so",
					  "ta","chi","tsu","te","to",
					  "na","ni","nu","ne","no",
					  "ha","hi","fu","he","ho",
					  "ma","mi","mu","me","mo",
					  "ya",     "yu",     "yo",
					  "ra","ri","ru","re","ro",
					  "wa",               "wo"});*/
	emplace_romaj_tab();	// We could have used list initialisation as below
				// but presence of 2 std::vector<string> initialised like this lead to seg fault when deallocating
	hirag_tab_format = std::vector<string> ({"a   i   u   e   o\n","あ  い  う  え  お\n","ka  ki  ku  ke  ko\n","か  き  く  け  こ\n","sa  shi su  se  so\n","さ  し  す  せ  そ\n","ta  chi tsu te  to\n","た  ち  つ  て  と\n","na  ni  nu  ne  no\n","な  に  ぬ  ね  の\n","ha  hi  fu  he  ho\n","は  ひ  ふ  へ  ほ\n","ma  mi  mu  me  mo\n","ま  み  む  め  も \n","ya      yu      yo\n","や      ゆ      よ\n","ra  ri  ru  re  ro\n","ら  り  る  れ  ろ\n","wa              wo\n","わ              を"});
}

void kana_dic::print_tab(int row)
{
	if (row<=0 || row > hirag_tab_format.size())
		row=hirag_tab_format.size();
	//setlocale(LC_ALL, "ja_JP.UTF8");
	/*std::cout<<"taille : " << hirag_tab.size() << std::endl;
	for (int i = 0; i<hirag_tab.size();i++) std::cout << hirag_tab.at(i);
	std::cout << std::endl;*/
	/*std::cout << "a   i   u   e   o\nあ  い  う  え  お\nka  ki  ku  ke  ko\nか  き  く  け  こ\nsa  shi su  se  so\nさ  し  す  せ  そ\nta  chi tsu te  to\nた  ち  つ  て  と\nna  ni  nu  ne  no\nな  に  ぬ  ね  の\nha  hi  fu  he  ho\nは  ひ  ふ  へ  ほ\nma  mi  mu  me  mo\nま  み  む  め  も \nya      yu      yo\nや      ゆ      よ\nra  ri  ru  re  ro\nら  り  る  れ  ろ\nwa              wo\nわ              を" << std::endl;*/
	for(int i=0;i<row*2;i++)
		std::cout << hirag_tab_format.at(i);
}

void kana_dic::print_kana(int index)
{
 	for (int i = index; i<index+3;i++) std::cout << hirag_tab.at(i);
}

void kana_dic::print_romaj(int index)
{
	 std::cout << romaj_tab.at(index);
}

void kana_dic::print_current()
{
 	for (int i = current_kana; i<current_kana+3;i++)
		std::cout << hirag_tab.at(i);
}

void kana_dic::print_current_romaj()
{
	 std::cout << romaj_tab.at(current_kana/3);
}

void kana_dic::draw_kana(int nb_row)
{
	static int last_kana(-1);
	int nb_active_kana(0);
	if(nb_row<=0 || nb_row>10)
		nb_row=10;
	switch(nb_row)
	{
		case 8 :
			nb_active_kana=NB_KANA-7;
			break;
		case 9 :
			nb_active_kana=NB_KANA-2;
			break;
		case 10 :
			nb_active_kana=NB_KANA;
			break;
		default :
			nb_active_kana=nb_row*5;
	}
	//std::cerr << nb_active_kana;
	do {
		current_kana=(rand()%nb_active_kana)*3;
	} while(current_kana==last_kana);
	last_kana=current_kana;
}

bool kana_dic::compare_kana(string input)
{
	for(string::iterator it=input.begin(); it!=input.end();it++)
		*it=(char)::tolower(*it);
	if (romaj_tab.at(current_kana/3).compare(input))
		return false;
	else return true;
}

void kana_dic::emplace_romaj_tab() //
{
	std::vector<string> tmp ({"a","i","u","e","o",
				  "ka","ki","ku","ke","ko",
				  "sa","shi","su","se","so",
				  "ta","chi","tsu","te","to",
				  "na","ni","nu","ne","no",
				  "ha","hi","fu","he","ho",
				  "ma","mi","mu","me","mo",
				  "ya",     "yu",     "yo",
				  "ra","ri","ru","re","ro",
				  "wa",               "wo"});
	for(int i=0;i<tmp.size();i++)
		romaj_tab.emplace_back(tmp.at(i));
}
