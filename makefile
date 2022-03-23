lab1: ./lab1/lab1.o
	g++ ./lab1/lab1.o -o ./lab1/lab1
	./lab1/lab1

lab1.o: ./lab1/lab1.cpp
	g++ -c ./lab1/lab1.cpp

lab2: ./lab2/Calculator.o
	g++ ./lab2/Calculator.o -o ./lab2/Calculator
	./lab2/Calculator

lab2.o: ./lab2/Calculator.cpp
	g++ -c ./lab2/Calculator.cpp

clean:
	rm *.o ./lab1/lab1