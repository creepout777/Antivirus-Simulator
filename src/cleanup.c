#include <stdio.h>
#include "../include/cleanup.h"
#include "../include/filelist.h"
#include "../include/siglist.h"

/*
purge_all:
  - Appeler free_list pour Clean, Suspect, Quarantine
  - Appeler free_sigs pour Signatures
  - Mettre tous les pointeurs à NULL
*/
void purge_all(void) {
    if (Clean != NULL) {
        free_list(&Clean);
        Clean = NULL;
    }

    if (Suspect != NULL) {
        free_list(&Suspect);
        Suspect = NULL;
    }

    if (Quarantine != NULL) {
        free_list(&Quarantine);
        Quarantine = NULL;
    }

    if (Signatures != NULL) {
        free_sigs(&Signatures);
        Signatures = NULL;
    }
}
