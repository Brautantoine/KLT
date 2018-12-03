#ifndef KANA_HPP
#define KANA_HPP

#include <vector>
#include <string>
#include <iostream>
#include <locale.h>
#include <stdio.h>

using std::string;

class kana_dic
{
	public :
	kana_dic();
	virtual ~kana_dic();
	string get_hirag(){return hirag_tab;}

	void afficher_tab();
	void afficher_tab(int index);

	private :

	void init_tab();
	
	string hirag_tab;
	std::vector<char> katak_tab;
	std::vector<char> romaj_tab;

};


#endif // KANA_HPP
