#include <stdio.h>
#include <string.h>
#include "scan.h"

// Fonction qui scanne les fichiers de Clean en recherchant les signatures
void scan_files(FileRec **clean, FileRec **suspect, Sig *sigs) {
    if (*clean == NULL) {
        printf("[SCAN] Aucun fichier dans Clean.\n");
        return;
    }

    if (sigs == NULL) {
        printf("[SCAN] Aucune signature chargée.\n");
        return;
    }

    FileRec *curr = *clean;
    FileRec *prev = NULL;

    while (curr != NULL) {
        int is_suspicious = 0;
        Sig *s = sigs;

        // On parcourt toutes les signatures
        while (s != NULL) {
            // strstr → cherche le pattern dans le contenu du fichier
            if (strstr(curr->data, s->pattern) != NULL) {
                is_suspicious = 1;
                break;
            }
            s = s->next;
        }

        if (is_suspicious) {
            printf("[SCAN] %s est suspect → déplacement vers Suspect.\n", curr->name);

            // Retirer de la liste Clean
            if (prev == NULL) {        // supprimer le premier nœud
                *clean = curr->next;
            } else {
                prev->next = curr->next;
            }

            // Déplacer vers Suspect
            curr->suspicious = 1;
            FileRec *toMove = curr;
            curr = curr->next;
            toMove->next = *suspect;
            *suspect = toMove;
        } 
        else {
            prev = curr;
            curr = curr->next;
        }
    }

    printf("[SCAN] Scan terminé ✅\n");
}
