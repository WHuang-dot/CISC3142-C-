lab1: ./lab1/lab1.o
	g++ ./lab1/lab1.o -o ./lab1/lab1
	./lab1/lab1

lab1.o: ./lab1/lab1.cpp
	g++ -c ./lab1/lab1.cpp

lab2: ./lab2/main.o
	g++ ./lab2/main.o -o ./lab2/main
	./lab2/main

lab2.o: ./lab2/main.cpp
	g++ -c ./lab2/main.cpp

clean:
	rm *.o ./lab1/lab1