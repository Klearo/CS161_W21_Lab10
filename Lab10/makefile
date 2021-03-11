CC=g++ -std=c++11
exe_file=task1

$(exe_file): solution.o memory.o
	$(CC) solution.o memory.o -o $(exe_file) 

solution.o: solution.cpp
	$(CC) -c solution.cpp 

memory.o: memory.cpp
	$(CC) -c memory.cpp 

clean: 
	rm -f *.o $(exe_file)


.PHONY: clean
