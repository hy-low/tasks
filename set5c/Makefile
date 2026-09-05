CC = gcc
CFLAGS = -Wall -Wextra -O2 -fsanitize=address -g

TARGET = main
OBJS = local.o main.o zip.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

local.o: local.c local.h zip.h
	$(CC) $(CFLAGS) -c local.c

main.o: main.c local.h zip.h
	$(CC) $(CFLAGS) -c main.c

stack.o: zip.c zip.h
	$(CC) $(CFLAGS) -c zip.c

clean:
	rm -f $(OBJS) $(TARGET)
