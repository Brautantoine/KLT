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
	
	bool core;
	int inp;
	kana_dic dic;
	int invalid_choice;
	char c;
};

#endif //KLT_CORE
