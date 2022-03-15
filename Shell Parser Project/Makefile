CXX = g++
CXXFLAGS = -std=c++11 -Wall -ftest-coverage -fprofile-arcs

OBJECTS = parse.o param.o

myshell: myshell.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY : clean
clean:
	$(RM) *.o *.gc*
