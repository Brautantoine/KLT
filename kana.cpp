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
	std::cout << "a  i  u  e  o\nあ い う え お\nka ki ku ke ko\nか き く け こ\nsa shisu se so\nさ し す せ そ\nta chitsute to\nた ち つ て と\nna ni nu ne no\nな に ぬ ね の\nha hi fu he ho\nは ひ ふ へ ほ\nma mi mu me mo\nま み む め も\nya    yu    yo\nや    ゆ    よ\nra ri ru re ro\nら り る れ ろ\nwa          wo\nわ          を" << std::endl;
}

void kana_dic::afficher_tab(int index)
{ 
 	for (int i = index; i<index+3;i++) std::cout << hirag_tab.at(i);
}
