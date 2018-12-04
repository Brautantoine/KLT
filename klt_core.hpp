#ifndef KLT_CORE
#define KLT_CORE

#include "kana.hpp"
#include <iostream>
#include <unistd.h>

class klt_core
{
	public:
	klt_core();
	~klt_core();
	int start_loop();

	private:

	void print_table();
	void start_random_kana();
	
	bool core;
	int inp;
	kana_dic dic;
	bool invalid_choice;
};

#endif //KLT_CORE
