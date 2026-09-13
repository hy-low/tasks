CC = gcc
CFLAGS = -Wall -Wextra -O2 -fsanitize=address -g

TARGET = main
OBJS = local.o main.o tasks.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

local.o: local.c local.h tasks.h
	$(CC) $(CFLAGS) -c local.c

main.o: main.c local.h tasks.h
	$(CC) $(CFLAGS) -c main.c

tasks.o: tasks.asm
	nasm -f elf64 tasks.asm -o tasks.o

clean:
	rm -f $(OBJS) $(TARGET)
