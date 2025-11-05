#ifndef SCAN_H
#define SCAN_H

#include "filelist.h"
#include "siglist.h"

/*
scan_files:
  - Parcourir la liste Clean
  - Pour chaque fichier, comparer bytes avec toutes les signatures
  - Si une signature est trouvée :
      * suspicious = 1
      * retirer le fichier de Clean
      * ajouter dans Suspect
  - Gérer prev et cur correctement
  - Afficher message pour chaque fichier suspect
*/
void scan_files(FileRec **clean, FileRec **suspect, Sig *sigs);

#endif
