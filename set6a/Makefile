CC = gcc
CFLAGS = -Wall -Wextra -O2 -fsanitize=address -g

TARGET = main
OBJS = local.o main.o arraylist.o linkedlist.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

local.o: local.c local.h arraylist.h linkedlist.h
	$(CC) $(CFLAGS) -c local.c

main.o: main.c local.h arraylist.h linkedlist.h
	$(CC) $(CFLAGS) -c main.c

arraylist.o: arraylist.c arraylist.h
	$(CC) $(CFLAGS) -c arraylist.c

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c

clean:
	rm -f $(OBJS) $(TARGET)
