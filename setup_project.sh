#!/bin/bash
# Toy Antivirus Project Initializer
# Run this script from inside your cloned project folder.

echo "🧩 Initializing Toy Antivirus project structure..."

# Create folders
mkdir -p include src data tests

# README
cat > README.md <<'EOF'
# Toy Antivirus Simulator

A beginner-friendly C project that simulates antivirus operations using linked lists.
Implements file scanning by string pattern detection, quarantine/restore functions,
and strict memory management rules.
EOF

# Makefile
cat > Makefile <<'EOF'
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
EOF

# Headers
cat > include/file.h <<'EOF'
#ifndef FILE_H
#define FILE_H

typedef struct FileRec {
    char *name;
    int size;
    char *content;
    int suspicious;
    struct FileRec *next;
} FileRec;

FileRec *create_file(const char *name, const char *content);
void free_file(FileRec *f);
void append_file(FileRec **head, FileRec *new_file);
FileRec *find_file(FileRec *head, const char *name);
int remove_file(FileRec **head, const char *name, FileRec **removed);

#endif
EOF

cat > include/sig.h <<'EOF'
#ifndef SIG_H
#define SIG_H

typedef struct Sig {
    char *pattern;
    struct Sig *next;
} Sig;

Sig *create_sig(const char *pattern);
void free_sig(Sig *s);
void append_sig(Sig **head, Sig *new_sig);
int remove_sig(Sig **head, const char *pattern);
int match_signature(const char *content, Sig *sig_head);

#endif
EOF

cat > include/antivirus.h <<'EOF'
#ifndef ANTIVIRUS_H
#define ANTIVIRUS_H

#include "file.h"
#include "sig.h"

void scan_files(FileRec **clean, FileRec **suspect, Sig *sigs);
void quarantine(FileRec **suspect, FileRec **quarantine, const char *name);
void restore(FileRec **quarantine, FileRec **clean, const char *name);
void report(FileRec *clean, FileRec *suspect, FileRec *quarantine);
void purge_all(FileRec **clean, FileRec **suspect, FileRec **quarantine, Sig **sigs);

#endif
EOF

cat > include/utils.h <<'EOF'
#ifndef UTILS_H
#define UTILS_H

char *str_duplicate(const char *src);
void zero_and_free(char *ptr);

#endif
EOF

# Source files
cat > src/main.c <<'EOF'
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file.h"
#include "sig.h"
#include "antivirus.h"
#include "utils.h"

int main() {
    FileRec *clean = NULL, *suspect = NULL, *quarantine = NULL;
    Sig *sigs = NULL;

    printf("=== Toy Antivirus Simulator ===\\n");
    printf("Commands: ADD_SIG, DEL_SIG, LOAD, SCAN, QUAR, RESTORE, REPORT, PURGE, EXIT\\n");

    // TODO: implement simple CLI loop here
    printf("Setup complete. CLI to be implemented.\\n");
    return 0;
}
EOF

cat > src/file.c <<'EOF'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "utils.h"

FileRec *create_file(const char *name, const char *content) {
    FileRec *f = malloc(sizeof(FileRec));
    if (!f) return NULL;
    f->name = str_duplicate(name);
    f->content = str_duplicate(content);
    f->size = strlen(content);
    f->suspicious = 0;
    f->next = NULL;
    return f;
}

void free_file(FileRec *f) {
    if (!f) return;
    free(f->name);
    zero_and_free(f->content);
    free(f);
}

void append_file(FileRec **head, FileRec *new_file) {
    if (!*head) {
        *head = new_file;
        return;
    }
    FileRec *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = new_file;
}

FileRec *find_file(FileRec *head, const char *name) {
    for (; head; head = head->next)
        if (strcmp(head->name, name) == 0) return head;
    return NULL;
}

int remove_file(FileRec **head, const char *name, FileRec **removed) {
    FileRec *prev = NULL, *cur = *head;
    while (cur) {
        if (strcmp(cur->name, name) == 0) {
            if (prev) prev->next = cur->next;
            else *head = cur->next;
            cur->next = NULL;
            *removed = cur;
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}
EOF

cat > src/sig.c <<'EOF'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sig.h"
#include "utils.h"

Sig *create_sig(const char *pattern) {
    Sig *s = malloc(sizeof(Sig));
    if (!s) return

