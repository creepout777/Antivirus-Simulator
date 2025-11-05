# Nom de l'exécutable
TARGET = toy_antivirus

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -g -std=c99 -Iincludes

# Fichiers sources
SRCS = src/main.c src/filelist.c src/siglist.c src/scan.c src/cleanup.c

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Règle par défaut
all: $(TARGET)

# Compilation de l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJS) $(TARGET)

# Rebuild complet : clean + all
rebuild: clean all

# Règles spéciales
.PHONY: all clean rebuild
