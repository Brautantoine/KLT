#ifndef KANA_HPP
#define KANA_HPP

#include <vector>

class kana_dic
{
	public :
	kana_dic();
	virtual ~kana_dic();

	private :

	void init_tab();
	
	std::vector<char> hirag_tab;
	std::vector<char> katak_tab;
	std::vector<char> romaj_tab;

};


#endif KANA_HPP
