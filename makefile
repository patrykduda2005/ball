#exe: $(wildcard *.cpp)
	#g++ *.cpp -o exe

exe: main.o render.o
	g++ main.o render.o -o exe

main.o: main.cpp
	g++ -c main.cpp

render.o: render.cpp render.h
	g++ -c render.cpp

clean:
	rm *.o exe
