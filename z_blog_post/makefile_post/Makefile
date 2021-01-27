CC = gcc
CFLAGS = -Werror -Wall -Wextra
TARGET = test
OBJECTS = a.o b.o main.o

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

clean :
	rm -f $(OBJECTS) $(TARGET)
