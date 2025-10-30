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
