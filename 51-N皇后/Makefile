CXX		= g++
CC		= gcc

a.out:cpp c 

cpp:main.cpp
	$(CXX) -DSIZE=4 $^ -o $@

c:main.c
	$(CC) -DSIZE=4 $^ -o $@
clean:
	rm ./c ./cpp
