CXX = g++
CXXFLAGS = -std=c++11 -Wall -ftest-coverage -fprofile-arcs

OBJECTS = generatePassword.o encryption.o hashTable.o hashNode.o testProgram.o

main: main.o $(OBJECTS)
		$(CXX) $(CXXFLAGS) -o $@ $^

clean:
		$(RM) *.o *.gc*
