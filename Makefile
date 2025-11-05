CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
TARGET = antivirus

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f src/*.o $(TARGET)
