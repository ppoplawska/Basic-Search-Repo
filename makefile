main: search.o 
	g++ search.o -o search
	
search.o: search.cpp
	g++ -c search.cpp
	
clean:
	rm -rf *o main
