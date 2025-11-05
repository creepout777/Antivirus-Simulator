#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/siglist.h"

// Liste globale de signatures
Sig *Signatures = NULL;

/*
create_sig:
  - Allouer un Sig
  - Copier pattern avec strdup
  - next = NULL
*/

Sig* create_sig(const char *pattern) {
    // TODO: Implémenter
    return NULL;
}

/*
insert_sig:
  - Ajouter la signature en tête de liste
*/

void insert_sig(Sig **head, Sig *node) {
    // TODO: Implémenter
}

/*
delete_sig:
  - Parcourir la liste
  - Comparer le pattern
  - Gérer tête, milieu, queue
  - Free pattern et node
*/

void delete_sig(Sig **head, const char *pattern) {
    // TODO: Implémenter
}

/*
print_sigs:
  - Parcourir et afficher chaque pattern
*/

void print_sigs(Sig *head) {
    // TODO: Implémenter
}

/*
free_sigs:
  - Parcourir, free pattern et node
  - Mettre head = NULL
*/

void free_sigs(Sig **head) {
    // TODO: Implémenter
}

