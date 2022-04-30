main: main.o logging.o
	g++ main.o logging.o -o main

main.o: main.cpp
	g++ -c main.cpp

logging.o: logging/logging.cpp logging/logging.h
	g++ -c logging/logging.cpp

clean:
	rm *.o main
