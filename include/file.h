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
