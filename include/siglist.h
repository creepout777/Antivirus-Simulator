#ifndef SIGLIST_H
#define SIGLIST_H

// Structure représentant une signature
typedef struct Sig {
    char *pattern;         // Pattern de signature
    struct Sig *next;      // Pointeur vers la signature suivante
} Sig;

// Liste globale de signatures
extern Sig *Signatures;

// Fonctions principales pour gérer les signatures
Sig* create_sig(const char *pattern);
void insert_sig(Sig **head, Sig *node);
void delete_sig(Sig **head, const char *pattern);
void print_sigs(Sig *head);
void free_sigs(Sig **head);

#endif

