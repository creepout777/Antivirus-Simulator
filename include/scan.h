#ifndef SCAN_H
#define SCAN_H

#include "filelist.h"
#include "siglist.h"

// Fonction de scan : déplace les fichiers suspects de Clean vers Suspect
void scan_files(FileRec **clean, FileRec **suspect, Sig *sigs);

#endif
