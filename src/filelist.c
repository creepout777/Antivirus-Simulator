#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filelist.h"

// Déclarez les listes globales
FileRec *Clean = NULL;
FileRec *Suspect = NULL;
FileRec *Quarantine = NULL;

/*
create_file:
  - Allouer un FileRec
  - Copier le nom avec strdup
  - Allouer et copier le contenu si size > 0
  - Initialiser suspicious à 0 et next à NULL
  - Retourner le pointeur
*/

FileRec* create_file(const char *name, const unsigned char *data, size_t size) {
    // TODO: Implémenter
    return NULL;
}

/*
insert_file:
  - Ajouter node en tête de la liste
*/

void insert_file(FileRec **head, FileRec *node) {
    // TODO: Implémenter
}

/*
remove_file:
  - Chercher un fichier par nom
  - Gérer tête, milieu, queue
  - Détacher node et le retourner
*/

FileRec* remove_file(FileRec **head, const char *name) {
    // TODO: Implémenter
    return NULL;
}

/*
find_file:
  - Parcourir la liste pour trouver un fichier par nom
  - Retourner le pointeur si trouvé, NULL sinon
*/

FileRec* find_file(FileRec *head, const char *name) {
    // TODO: Implémenter
    return NULL;
}

/*
move_file:
  - Appeler remove_file pour retirer le fichier
  - Appeler insert_file pour l'ajouter dans la nouvelle liste
*/

void move_file(FileRec **from, FileRec **to, const char *name) {
    // TODO: Implémenter
}

/*
print_list:
  - Parcourir la liste
  - Afficher nom, taille, état (suspect ou clean)
  - Afficher le total de fichiers et de bytes
*/

void print_list(const char *title, FileRec *head) {
    // TODO: Implémenter
}

/*
free_list:
  - Parcourir la liste
  - Free bytes, free name, free node
  - Mettre head = NULL à la fin
*/

void free_list(FileRec **head) {
    // TODO: Implémenter
}

