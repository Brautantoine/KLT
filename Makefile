klt_core.o : klt_core.cpp

	g++ klt_core.cpp -c -std=c++11

kana.o : kana.cpp

	g++ kana.cpp -c -std=c++11 

all : main.cpp kana.o

	 g++ main.cpp -o klt.out kana.o klt_core.o -std=c++11

install : klt.out

	cp klt.out /usr/bin/klt
