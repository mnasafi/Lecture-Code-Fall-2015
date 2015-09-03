# first target in a Makefile is the default target (videos in this file)
# this rule "makes" the final executable "videos"
my_object: my_object.o test.o
	g++ -Wall -pedantic -g -o my_object my_object.o test.o

# this rule "makes" main.o
# main.o depends on video.h and main.cpp
test.o: my_object.h test.cpp
	g++ -Wall -pedantic -g -c test.cpp

# this rule "makes" video.o
# video.o depends on video.h and video.cpp
my_object.o: my_object.h my_object.cpp
	g++ -Wall -pedantic -g -c my_object.cpp

clean:
	rm -f my_object.o test.o my_object my_object.exe
