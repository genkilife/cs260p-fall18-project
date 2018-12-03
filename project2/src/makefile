
CC=g++ -std=c++11

all: main testMain

main:	
	${CC}	-o	MAIN MAIN.cpp 

testMain:
	${CC}	-o	testMain testMain.cpp

# dependencies to compile used libraries
.PHONY: clean
clean:
	-rm MAIN testMain
