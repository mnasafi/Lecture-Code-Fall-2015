istack: main.o istack.o
	g++ -Wall -pedantic -g -o istack main.o istack.o

main.o: main.cpp istack.h
	g++ -Wall -pedantic -g -c main.cpp

istack.o: istack.cpp istack.h
	g++ -Wall -pedantic -g -c istack.cpp

clean:
	rm -f *.o istack
