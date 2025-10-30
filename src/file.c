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
