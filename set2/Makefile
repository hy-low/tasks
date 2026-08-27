CC = gcc
CFLAGS = -Wall -Wextra -O2 -fsanitize=address

TARGET = main
OBJS = main.o tasks.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c tasks.h
	$(CC) $(CFLAGS) -c main.c

tasks.o: tasks.c tasks.h
	$(CC) $(CFLAGS) -c tasks.c

clean:
	rm -f $(OBJS) $(TARGET)
