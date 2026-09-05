CC = gcc
CFLAGS = -Wall -Wextra -O2 -fsanitize=address -g

TARGET = main
OBJS = local.o main.o csv.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

local.o: local.c local.h csv.h
	$(CC) $(CFLAGS) -c local.c

main.o: main.c local.h csv.h
	$(CC) $(CFLAGS) -c main.c

stack.o: csv.c csv.h
	$(CC) $(CFLAGS) -c csv.c

clean:
	rm -f $(OBJS) $(TARGET)
