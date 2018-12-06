klt_core.o : klt_core.cpp

	g++ klt_core.cpp -c -std=c++11 -o klt_core.o

kana.o : kana.cpp

	g++  kana.cpp -c -std=c++11 -o kana.o

all : main.cpp kana.o klt_core.o

	 g++ main.cpp -o klt.out kana.o klt_core.o -std=c++11 -lncurses

install : klt.out

	cp klt.out /usr/bin/klt
