all: C.exe

C.exe: C.cpp
	g++ -o C.exe C.cpp -std=c++11 -Wall -Wextra -Wpedantic

clean:
	rm *.exe
