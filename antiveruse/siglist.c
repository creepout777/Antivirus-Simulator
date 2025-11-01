#include "siglist.h"

// Create a new signature node
Sig* create_sig(int id, const char *pattern) {
    Sig *newSig = (Sig*) malloc(sizeof(Sig));
    if (!newSig) {
        printf("Error: memory allocation failed.\n");
        return NULL;
    }

    newSig->id = id;
    strcpy(newSig->pattern, pattern);
    newSig->next = NULL;
    return newSig;
}

// Insert a signature at the end of the list
Sig* insert_sig(Sig *head, Sig *new_sig) {
    if (new_sig == NULL) return head;

    if (head == NULL) {
        return new_sig;
    }

    Sig *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_sig;
    return head;
}

// Delete a signature by its ID
Sig* delete_sig(Sig *head, int id) {
    if (head == NULL) return NULL;

    Sig *temp = head;
    Sig *prev = NULL;

    if (head->id == id) {
        head = head->next;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Signature with ID %d not found.\n", id);
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

// Display all signatures
void print_sigs(Sig *head) {
    if (head == NULL) {
        printf("No signatures available.\n");
        return;
    }

    Sig *temp = head;
    printf("\n=== Signature List ===\n");
    while (temp != NULL) {
        printf("ID: %d | Pattern: %s\n", temp->id, temp->pattern);
        temp = temp->next;
    }
    printf("======================\n");
}

// Free all allocated memory
void free_sigs(Sig *head) {
    Sig *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
