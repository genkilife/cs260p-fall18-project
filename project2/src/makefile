
CC=g++ -std=c++11

all: main testMain

doalg_WL.o: doalg_WL.cpp

doalg_YK.o: doalg_YK.cpp

main: doalg_WL.o doalg_YK.o	
	${CC}	-o	MAIN MAIN.cpp doalg_WL.o doalg_YK.o

testMain: doalg_WL.o doalg_YK.o
	${CC}	-o	testMain testMain.cpp doalg_WL.o doalg_YK.o


# dependencies to compile used libraries
.PHONY: clean
clean:
	-rm MAIN testMain *.o
