CC = gcc
CFLAGS = -Wall -Wextra -O2 -fsanitize=address -g

TARGET = main
OBJS = local.o main.o factorial.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

local.o: local.c local.h factorial.h
	$(CC) $(CFLAGS) -c local.c

main.o: main.c local.h factorial.h
	$(CC) $(CFLAGS) -c main.c

factorial.o: factorial.c factorial.h
	$(CC) $(CFLAGS) -c factorial.c

clean:
	rm -f $(OBJS) $(TARGET)
