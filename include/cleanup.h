#ifndef CLEANUP_H
#define CLEANUP_H

/* purge_all: - Appeler free_list pour Clean, Suspect, Quarantine 
              - Appeler free_sigs pour Signatures 
              - Mettre tous les pointeurs à NULL 
*/
void purge_all(void);

#endif
