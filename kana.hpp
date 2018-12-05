#ifndef KANA_HPP
#define KANA_HPP

#include <vector>
#include <string>
#include <iostream>
#include <time.h>

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
