CXX = g++
CXXFLAGS = -std=c++11 -Wall -ftest-coverage -fprofile-arcs

OBJECTS = graph.o tour.o geneticAlgorithm.o generation.o bruteForce.o timer.o

main: main.o $(OBJECTS)
		$(CXX) $(CXXFLAGS) -o $@ $^

clean:
		$(RM) *.o *.gc*
