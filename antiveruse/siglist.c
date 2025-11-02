#include "siglist.h"

// Create a new signature
Sig* create_sig(char name[], int id) {
    Sig *newSig = (Sig*) malloc(sizeof(Sig));
    if (newSig == NULL) {
        printf("Memory allocation error.\n");
        return NULL;
    }
    strcpy(newSig->name, name);
    newSig->id = id;
    newSig->next = NULL;
    return newSig;
}

// Insert a signature at the beginning of the list
void insert_sig(Sig **head, char name[], int id) {
    Sig *newSig = create_sig(name, id);
    if (newSig == NULL) return;
    newSig->next = *head;
    *head = newSig;
}

// Delete a signature by ID
void delete_sig(Sig **head, int id) {
    Sig *temp = *head;
    Sig *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Signature with ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Signature %d deleted successfully.\n", id);
}

// Display all signatures
void print_sigs(Sig *head) {
    Sig *current = head;
    if (current == NULL) {
        printf("No signatures found.\n");
        return;
    }

    printf("\n--- Signature List ---\n");
    while (current != NULL) {
        printf("ID: %d | Name: %s\n", current->id, current->name);
        current = current->next;
    }
    printf("-----------------------\n");
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

