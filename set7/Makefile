CC = gcc
CFLAGS = -Wall -Wextra -O2 -fsanitize=address -g

TARGET = main
OBJS = local.o main.o cpu.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

local.o: local.c local.h cpu.h
	$(CC) $(CFLAGS) -c local.c

main.o: main.c local.h cpu.h
	$(CC) $(CFLAGS) -c main.c

stack.o: cpu.c cpu.h
	$(CC) $(CFLAGS) -c cpu.c

clean:
	rm -f $(OBJS) $(TARGET)
