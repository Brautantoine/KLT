#include <iostream>
#include "kana.hpp"
#include <time.h>
#include <unistd.h>

#define NB_KANA 42

int main()
{
	bool core(true);
	int inp(0);
	bool invalid_choice(false);
	kana_dic dic;
	/*int t(0);
	srand(time(NULL));
	
std::cout << "hello wolrd";*/
	dic.afficher_tab();
	/*std::cout << "helloあいうえwolrdお" << std::endl;
	t=(rand()%NB_KANA)*3;
	std::cout << u8"Hiragana aléatoire : " << t;  std::cout << "あいうえお" << std::endl;dic.afficher_tab(t);*/

	while(core)
	{
		
		system("clear");
		std::cout << "\n\t\tWelcome to KLT\n\n\t1 - Go for some random kana\n\t2 - Show Kana Table\n\t3 - Quit and come back later\n\n\tYour choice : " ;
		if(invalid_choice) std::cout << "[Your choice is in another castle] : ";  
		std::cin.sync();
		std::cin >> inp;

		switch(inp)
		{
			case 1 :
				//TODO
				{
				bool core2(true);
				string input; // String and using string declare in kana.hpp
				while(core2){
				system("clear");
					dic.draw_kana();
					std::cout << "Wich Romaji correspond to the kana ";
					dic.print_current();
					std::cout << " : ";
					std::cin >> input;
					if(dic.compare_kana(input)) {std::cout<<std::endl<<"Correct ";dic.print_current();std::cout << " -> ";dic.print_current_romaj();std::cout << " !" << std::endl;}
					else {std::cout<<std::endl<<"Wrong ";dic.print_current();std::cout << " -> ";dic.print_current_romaj();std::cout << " !" << std::endl;}
					std::cout << "Continue ? (Y/N) : ";std::cin >> input; if (input == "N")core2=false;}
				break;}
			case 2 :
				invalid_choice=false;
				system("clear");
				dic.afficher_tab();
				std::cout << std::endl <<  "Enter q to quit";
				//std::cin >> inp ;
				std::cin.get();
				break;
			case 3 :
				core=false;
				break;
			default :
				invalid_choice=true;			
		}
	}

	return 0;
}
