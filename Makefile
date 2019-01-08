Kana_trainer.o : Kana_trainer.cpp Kana_trainer.hpp

	g++ Kana_trainer.cpp -c -std=c++11 -o Kana_trainer.o

klt_core.o : klt_core.cpp klt_core.hpp

	g++ klt_core.cpp -c -std=c++11 -o klt_core.o

kana.o : kana.cpp kana.hpp

	g++  kana.cpp -c -std=c++11 -o kana.o

utils.o : utils.cpp utils.hpp

	g++  utils.cpp -c -std=c++11 -o utils.o

all : main.cpp kana.o klt_core.o utils.o Kana_trainer.o

	 g++ main.cpp -o klt.out Kana_trainer.o kana.o klt_core.o utils.o -std=c++11 -lncursesw

install : klt.out

	cp klt.out /usr/bin/klt
