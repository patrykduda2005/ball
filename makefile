#exe: $(wildcard *.cpp)
	#g++ *.cpp -o exe

OBJECTS=$(patsubst %.cpp,%.o,$(wildcard *.cpp))

exe: $(OBJECTS)
	g++ $(OBJECTS) -o exe

%.o: %.cpp %.h
	g++ -c $<


clean:
	rm *.o exe
