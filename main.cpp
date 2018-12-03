#include <iostream>
#include "kana.hpp"
#include <time.h>

int main()
{
	int t(0);
	srand(time(NULL));
	kana_dic dic;
std::cout << "hello wolrd";
	dic.afficher_tab();
	std::cout << "helloあいうえwolrdお" << std::endl;
	t=rand()%dic.get_hirag().size();
	std::cout << u8"Hiragana aléatoire : ";  std::cout << "あいうえお" << std::endl;dic.afficher_tab(0);
	return 0;
}
