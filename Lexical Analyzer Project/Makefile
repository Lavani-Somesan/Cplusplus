CC=gcc
CFLAGS= -g -Wall

OBJECTS = lexer.o symbolTable.o parser.o assembly.o

main: main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	$(RM) *.o

