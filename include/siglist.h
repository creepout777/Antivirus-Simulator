#ifndef SIGLIST_H
#define SIGLIST_H

// Structure représentant une signature (nœud de liste chaînée simple)
typedef struct Sig {
    char *pattern;           // Le motif de signature (chaîne allouée dynamiquement)
    struct Sig *next;        // Pointeur vers le nœud Sig suivant
} Sig;

// Déclaration de la tête de liste (variable externe utilisée par tout le projet)
extern Sig *Signatures;

// Prototypes des fonctions de gestion de la liste
Sig* create_sig(const char *pattern);
void insert_sig(Sig **head, Sig *node);
void delete_sig(Sig **head, const char *pattern);
void print_sigs(Sig *head);
void free_sigs(Sig **head);

#endif
