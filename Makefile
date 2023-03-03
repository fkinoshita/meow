CC=gcc

meow: main.o
	$(CC) -o meow main.o

clean:
	rm meow main.o
