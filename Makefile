kana.o : kana.cpp

	g++ kana.cpp -c -std=c++11 

all : main.cpp kana.o

	 g++ main.cpp -o klt.out kana.o -std=c++11
