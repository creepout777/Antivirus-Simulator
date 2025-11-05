#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/filelist.h"

// Les trois listes principales
FileRec *Clean = NULL;
FileRec *Suspect = NULL;
FileRec *Quarantine = NULL;

/*
create_file :
  Crée un nouveau fichier (nœud)
  - Alloue la mémoire
  - Copie le nom et le contenu
  - Initialise les champs
*/
FileRec* create_file(const char *name, const unsigned char *data, size_t size) {
    if (name == NULL) return NULL;

    FileRec *node = malloc(sizeof(FileRec));
    if (node == NULL) return NULL;

    node->name = strdup(name);
    if (node->name == NULL) {
        free(node);
        return NULL;
    }

    if (size > 0 && data != NULL) {
        node->bytes = malloc(size);
        if (node->bytes == NULL) {
            free(node->name);
            free(node);
            return NULL;
        }
        memcpy(node->bytes, data, size);
    } else {
        node->bytes = NULL;
    }

    node->size = size;
    node->suspicious = 0;
    node->next = NULL;

    return node;
}

/*
insert_file :
  Ajoute un fichier au début de la liste
*/
void insert_file(FileRec **head, FileRec *node) {
    if (head == NULL || node == NULL) return;
    node->next = *head;
    *head = node;
}

/*
remove_file :
  Retire un fichier d'une liste par son nom
  et renvoie le nœud trouvé (sans le libérer)
*/
FileRec* remove_file(FileRec **head, const char *name) {
    if (head == NULL || *head == NULL || name == NULL) return NULL;

    FileRec *curr = *head;
    FileRec *prev = NULL;

    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            if (prev == NULL)
                *head = curr->next; // tête de liste
            else
                prev->next = curr->next; // milieu ou fin
            curr->next = NULL;
            return curr;
        }
        prev = curr;
        curr = curr->next;
    }

    return NULL; // non trouvé
}

/*
find_file :
  Cherche un fichier dans la liste par son nom
*/
FileRec* find_file(FileRec *head, const char *name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

/*
move_file :
  Déplace un fichier d'une liste vers une autre
*/
void move_file(FileRec **from, FileRec **to, const char *name) {
    if (from == NULL || to == NULL || name == NULL) return;
    FileRec *file = remove_file(from, name);
    if (file != NULL)
        insert_file(to, file);
}

/*
print_list :
  Affiche tous les fichiers d'une liste
*/
void print_list(const char *title, FileRec *head) {
    printf("=== %s ===\n", title);
    int count = 0;
    size_t total = 0;

    while (head != NULL) {
        printf("  %-20s | %5zu bytes | %s\n",
               head->name,
               head->size,
               head->suspicious ? "SUSPECT" : "CLEAN");
        count++;
        total += head->size;
        head = head->next;
    }

    if (count == 0)
        printf("  (empty)\n");

    printf("-- Total: %d files, %zu bytes --\n\n", count, total);
}

/*
free_list :
  Libère toute la mémoire d'une liste
*/
void free_list(FileRec **head) {
    if (head == NULL) return;

    FileRec *curr = *head;
    while (curr != NULL) {
        FileRec *next = curr->next;

        free(curr->bytes);
        free(curr->name);
        free(curr);

        curr = next;
    }
    *head = NULL;
}
