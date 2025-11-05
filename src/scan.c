#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/filelist.h"
#include "../include/siglist.h"
#include "../include/scan.h"

/*
scan_files:
  - Parcourt la liste Clean
  - Ouvre chaque fichier sur le disque (curr->name est le chemin)
  - Lit le contenu dans un buffer
  - Cherche chaque pattern de signature avec strstr()
  - Si trouvé → fichier suspect : déplacer vers la liste Suspect
*/
void scan_files(FileRec **clean, FileRec **suspect, Sig *sigs) {
    if (!clean || !*clean || !sigs) return;

    FileRec *curr = *clean;
    FileRec *prev = NULL;

    while (curr) {
        int infected = 0;

        // Ouvrir le fichier à partir de son nom (chemin)
        FILE *fp = fopen(curr->name, "r");
        if (!fp) {
            printf("[!] Impossible d’ouvrir %s\n", curr->name);
            prev = curr;
            curr = curr->next;
            continue;
        }

        // Lire le contenu du fichier
        fseek(fp, 0, SEEK_END);
        long fsize = ftell(fp);
        rewind(fp);

        char *buffer = malloc(fsize + 1);
        if (!buffer) {
            fclose(fp);
            printf("[!] Erreur mémoire sur %s\n", curr->name);
            prev = curr;
            curr = curr->next;
            continue;
        }

        fread(buffer, 1, fsize, fp);
        buffer[fsize] = '\0';
        fclose(fp);

        // Comparer avec les signatures
        for (Sig *s = sigs; s; s = s->next) {
            if (strstr(buffer, s->pattern)) {
                infected = 1;
                break;
            }
        }

        free(buffer);

        if (infected) {
            printf("[!] Suspicious file detected: %s\n", curr->name);
            curr->suspicious = 1;

            FileRec *found = remove_file(clean, curr->name);
            insert_file(suspect, found);

            if (prev)
                curr = prev->next;
            else
                curr = *clean;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

