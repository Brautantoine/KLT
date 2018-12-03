#include "kana.hpp"


const int kana_dic::NB_KANA=44;

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
	romaj_tab = std::vector<string> ({"a","i","u","e","o",
					  "ka","ki","ku","ke","ko",
					  "sa","shi","su","se","so",
					  "ta","chi","tsu","te","to",
					  "na","ni","nu","ne","no",
					  "ha","hi","fu","he","ho",
					  "ma","mi","mu","me","mo",
					  "ya",     "yu",     "yo",
					  "ra","ri","ru","re","ro",
					  "wa",               "wo"});
}

void kana_dic::afficher_tab()
{
	//setlocale(LC_ALL, "ja_JP.UTF8");
	/*std::cout<<"taille : " << hirag_tab.size() << std::endl;
	for (int i = 0; i<hirag_tab.size();i++) std::cout << hirag_tab.at(i);
	std::cout << std::endl;*/
	std::cout << "a   i   u   e   o\nあ  い  う  え  お\nka  ki  ku  ke  ko\nか  き  く  け  こ\nsa  shi su  se  so\nさ  し  す  せ  そ\nta  chi tsu te  to\nた  ち  つ  て  と\nna  ni  nu  ne  no\nな  に  ぬ  ね  の\nha  hi  fu  he  ho\nは  ひ  ふ  へ  ほ\nma  mi  mu  me  mo\nま  み  む  め  も \nya      yu      yo\nや      ゆ      よ\nra  ri  ru  re  ro\nら  り  る  れ  ろ\nwa              wo\nわ              を" << std::endl;
}

void kana_dic::afficher_tab(int index)
{ 
 	for (int i = index; i<index+3;i++) std::cout << hirag_tab.at(i);
}

void kana_dic::print_romaj(int index)
{ 
	 std::cout << romaj_tab.at(index);
}

void kana_dic::print_current()
{ 
 	for (int i = current_kana; i<current_kana+3;i++) std::cout << hirag_tab.at(i);
}

void kana_dic::print_current_romaj()
{ 
	 std::cout << romaj_tab.at(current_kana/3);
}

void kana_dic::draw_kana()
{
	current_kana=(rand()%NB_KANA)*3;
}

bool kana_dic::compare_kana(string input)
{
	for(string::iterator it=input.begin(); it!=input.end();it++)*it=(char)::tolower(*it);
	if (romaj_tab.at(current_kana/3).compare(input)) return false;
	else return true;
}
