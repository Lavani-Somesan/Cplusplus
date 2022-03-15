CXX = g++
CXXFLAGS = -std=c++11 -Wall -ftest-coverage -fprofile-arcs

OBJECTS = customer.o priorityQueue.o fifoQueue.o service.o analyticalModel.o

main: main.o $(OBJECTS)
		$(CXX) $(CXXFLAGS) -o $@ $^

clean:
		$(RM) *.o *.gc*
