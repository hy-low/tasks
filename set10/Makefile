CC = gcc
CFLAGS = -Wall -Wextra -O2 -fsanitize=address -g

TARGET = main
OBJS = local.o main.o eval.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

local.o: local.c local.h eval.h
	$(CC) $(CFLAGS) -c local.c

main.o: main.c local.h eval.h
	$(CC) $(CFLAGS) -c main.c

eval.o: eval.asm
	nasm -f elf64 eval.asm -o eval.o

clean:
	rm -f $(OBJS) $(TARGET)
