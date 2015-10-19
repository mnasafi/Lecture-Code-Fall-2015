iqueue: main.o iqueue.o
	g++ -Wall -pedantic -g -o iqueue main.o iqueue.o

main.o: main.cpp iqueue.h
	g++ -Wall -pedantic -g -c main.cpp

iqueue.o: iqueue.cpp iqueue.h
	g++ -Wall -pedantic -g -c iqueue.cpp

clean:
	rm -f *.o iqueue
