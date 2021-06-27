all:
	g++ -Wall -O3 -o Main main.cpp

clean:
	rm -f main *.o
