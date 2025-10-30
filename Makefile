CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

all: antivirus

antivirus: $(OBJ)
	$(CC) $(CFLAGS) -o antivirus $(OBJ)

run: antivirus
	./antivirus

clean:
	rm -f src/*.o antivirus
