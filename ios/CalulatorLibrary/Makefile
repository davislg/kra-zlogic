all: build

build: clean  test.o logic.o operator.o numericBase.o binaryLogic.o octalLogic.o decimalLogic.o hexLogic.o
	g++ test.o logic.o operator.o numericBase.o binaryLogic.o octalLogic.o decimalLogic.o hexLogic.o -o test

#clearScreen:
#	clear

test.o: test.cpp
	g++ -c -g test.cpp

logic.o: logic.cpp
	g++ -c -g logic.cpp

operator.o: operator.cpp
	g++ -c -g operator.cpp

numericBase.o: numericBase.cpp
	g++ -c -g numericBase.cpp

binaryLogic.o: binaryLogic.cpp
	g++ -c -g binaryLogic.cpp

octalLogic.o: octalLogic.cpp
	g++ -c -g octalLogic.cpp

decimalLogic.o: decimalLogic.cpp
	g++ -c -g decimalLogic.cpp

hexLogic.o: hexLogic.cpp
	g++ -c -g hexLogic.cpp

clean:
	rm -rf *.o test
	
