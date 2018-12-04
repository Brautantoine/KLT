#include <iostream>
#include "kana.hpp"
#include <time.h>
#include <unistd.h>
#include "klt_core.hpp"

//#define NB_KANA 42

int main()
{

	klt_core main_loop;
	
	main_loop.start_loop();
	
	return 0;
}
