#include "kana.hpp"




kana_dic::kana_dic()
{
	init_tab();
}

kana_dic::~kana_dic()
{

}

void kana_dic::init_tab()
{
	hirag_tab = string ("あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわ");
}

void kana_dic::afficher_tab()
{
	//setlocale(LC_ALL, "ja_JP.UTF8");
std::cout<<"taille : " << hirag_tab.size() << std::endl;
	for (int i = 0; i<hirag_tab.size();i++) std::cout << hirag_tab.at(i);
	std::cout << std::endl;
}

void kana_dic::afficher_tab(int index)
{ 
 	for (int i = index+12; i<index+15;i++) std::cout << hirag_tab.at(i);
}
