#include "klt_core.hpp"

klt_core::klt_core()
{
	core=true;
	inp=0;
	invalid_choice=false;
}

klt_core::~klt_core()
{

}

int klt_core::start_loop()
{
	while(core)
	{
		system("clear");
		std::cout << "\n\t\tWelcome to KLT\n\n\t1 - Go for some random kana\n\t2 - Show Kana Table\n\t3 - Quit and come back later\n\n\tYour choice : " ;
		if(invalid_choice)
			std::cout << "[Your choice is in another castle] : ";  

		std::cin.sync();
		std::cin >> inp;

		switch(inp)
		{
			case 1 :
				start_random_kana();
				break;
			case 2 :
				print_table();
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

void klt_core::print_table()
{
	char c(0);
	invalid_choice=false;
	system("clear");
	dic.afficher_tab();
	std::cout << std::endl <<  "Enter q to quit";
	while(c!='q')std::cin.get(c);
}

void klt_core::start_random_kana()
{
	bool core2(true);
	string input; // String and using string declare in kana.hpp

	while(core2)
	{
		system("clear");

		dic.draw_kana();
		std::cout << "Wich Romaji correspond to the kana ";
		dic.print_current();
		std::cout << " : ";

		std::cin >> input;
		
		if(dic.compare_kana(input)) 
		{
			std::cout<<std::endl<<"Correct ";
			dic.print_current();std::cout << " -> ";
			dic.print_current_romaj();std::cout << " !" << std::endl;
		}
		else 
		{
			std::cout<<std::endl<<"Wrong ";
			dic.print_current();
			std::cout << " -> ";
			dic.print_current_romaj();
			std::cout << " !" << std::endl;
		}
		std::cout << "Continue ? (Y/N) : ";

		std::cin >> input;

		if (input == "N" || input == "n")
			core2=false;
	}	
}
