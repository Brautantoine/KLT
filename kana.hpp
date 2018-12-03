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

	void afficher_tab();
	void afficher_tab(int index);
	void print_romaj(int index);
	void print_current();
	void print_current_romaj();
	bool compare_kana(string input);
	void draw_kana();

	static const int NB_KANA;

	private :

	void init_tab();
	
	string hirag_tab;
	//string katak_tab; Not implemented yet
	std::vector<string> romaj_tab;
	int current_kana;

};



#endif // KANA_HPP
