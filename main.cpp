#include <iostream>
#include "kana.hpp"
#include <time.h>

#define NB_KANA 42

int main()
{
	int t(0);
	srand(time(NULL));
	kana_dic dic;
std::cout << "hello wolrd";
	dic.afficher_tab();
	std::cout << "helloあいうえwolrdお" << std::endl;
	t=(rand()%NB_KANA)*3;
	std::cout << u8"Hiragana aléatoire : " << t;  std::cout << "あいうえお" << std::endl;dic.afficher_tab(t);
	return 0;
}
