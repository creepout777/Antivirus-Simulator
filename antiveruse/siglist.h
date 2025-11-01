#ifndef SIGLIST_H
#define SIGLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing a signature
typedef struct Sig {
    int id;                  // Unique ID for each signature
    char pattern[50];        // Signature pattern (string)
    struct Sig *next;        // Pointer to the next signature
} Sig;

// Function prototypes
Sig* create_sig(int id, const char *pattern);
Sig* insert_sig(Sig *head, Sig *new_sig);
Sig* delete_sig(Sig *head, int id);
void print_sigs(Sig *head);
void free_sigs(Sig *head);

#endif


    