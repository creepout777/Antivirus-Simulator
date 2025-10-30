#ifndef FILELIST_H
#define FILELIST_H

#include <stddef.h>

// Structure représentant un fichier
typedef struct FileRec {
    char *name;            // Nom du fichier
    size_t size;           // Taille en octets
    unsigned char *bytes;  // Contenu du fichier (optionnel)
    int suspicious;        // 0 = clean, 1 = suspect
    struct FileRec *next;  // Pointeur vers le fichier suivant
} FileRec;

// Listes globales
extern FileRec *Clean;
extern FileRec *Suspect;
extern FileRec *Quarantine;

// Fonctions principales pour gérer les fichiers
FileRec* create_file(const char *name, const unsigned char *data, size_t size);
void insert_file(FileRec **head, FileRec *node);
FileRec* remove_file(FileRec **head, const char *name);
FileRec* find_file(FileRec *head, const char *name);
void move_file(FileRec **from, FileRec **to, const char *name);
void print_list(const char *title, FileRec *head);
void free_list(FileRec **head);

#endif

