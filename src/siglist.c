#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/siglist.h"

/**
 * create_sig: Alloue un nouveau nœud Sig et copie le pattern.
 * Gère l'allocation de la structure et de la chaîne de caractères.
 */
Sig* create_sig(const char *pattern) {
    if (!pattern) {
        return NULL;
    }

    Sig *new_sig = (Sig *)malloc(sizeof(Sig));
    if (!new_sig) {
        perror("Erreur: malloc Sig");
        return NULL;
    }

    // Allouer et copier le pattern. strdup = malloc + strcpy
    new_sig->pattern = strdup(pattern);
    if (!new_sig->pattern) {
        perror("Erreur: strdup pattern");
        free(new_sig); // Libération en cas d'échec
        return NULL;
    }

    new_sig->next = NULL;
    return new_sig;
}

/**
 * insert_sig: Insère un nœud Sig en tête de liste (opération O(1)).
 */
void insert_sig(Sig **head, Sig *node) {
    if (!head || !node) {
        return;
    }
    
    // 1. Le nouveau nœud pointe vers ce qui était l'ancienne tête
    node->next = *head;
    // 2. La tête de liste pointe maintenant vers le nouveau nœud
    *head = node;
}

/**
 * delete_sig: Supprime le premier nœud Sig qui correspond au pattern.
 * Implémente le "pointer rewiring" et libère le nœud et son contenu.
 */
void delete_sig(Sig **head, const char *pattern) {
    if (!head || !*head || !pattern) {
        return; 
    }

    Sig *current = *head;
    Sig *prev = NULL;

    // Cas 1: Suppression en tête
    if (strcmp(current->pattern, pattern) == 0) {
        *head = current->next;      // Avancer la tête
        free(current->pattern);     
        free(current);              
        return;
    }

    // Cas 2: Recherche (Milieu/Fin)
    while (current != NULL && strcmp(current->pattern, pattern) != 0) {
        prev = current;
        current = current->next;
    }

    // Le pattern n'a pas été trouvé
    if (current == NULL) {
        return;
    }

    // Nœud trouvé: Remaillage des pointeurs
    prev->next = current->next; 
    free(current->pattern);
    free(current);
}

/**
 * print_sigs: Affiche tous les patterns de la liste des signatures (pour REPORT).
 */
void print_sigs(Sig *head) {
    if (!head) {
        printf("  -> Liste des signatures vide.\n");
        return;
    }

    Sig *current = head;
    int i = 1;
    printf("--- Liste des Signatures ---\n");
    while (current != NULL) {
        printf("  [%d] Pattern: '%s'\n", i, current->pattern);
        current = current->next;
        i++;
    }
    printf("--- Total: %d signatures ---\n", i - 1);
}

/**
 * free_sigs: Libère récursivement tous les nœuds de la liste et leur pattern.
 * Met le pointeur de tête à NULL pour la sécurité (anti-fuites).
 */
void free_sigs(Sig **head) {
    if (!head || !*head) {
        return;
    }

    Sig *current = *head;
    Sig *next_node;

    while (current != NULL) {
        next_node = current->next;  // 1. Sauvegarder l'adresse du prochain
        
        if (current->pattern) {
             free(current->pattern);    // 2. Libérer le pattern (chaîne)
        }
       
        free(current);              // 3. Libérer le nœud Sig
        
        current = next_node;        // 4. Avancer
    }

    // Indiquer au programme que la liste est vide
    *head = NULL;
}
