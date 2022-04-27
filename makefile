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

lab3: ./lab3/cpp/main.o
	g++ ./lab3/cpp/main.o -o ./lab3/cpp/main
	./lab3/cpp/main

lab3.o: ./lab3/cpp/main.cpp
	g++ -c ./lab3/cpp/main.cpp


clean:
	rm *.o ./lab1/lab1