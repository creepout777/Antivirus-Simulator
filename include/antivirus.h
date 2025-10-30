#ifndef ANTIVIRUS_H
#define ANTIVIRUS_H

#include "file.h"
#include "sig.h"

void scan_files(FileRec **clean, FileRec **suspect, Sig *sigs);
void quarantine(FileRec **suspect, FileRec **quarantine, const char *name);
void restore(FileRec **quarantine, FileRec **clean, const char *name);
void report(FileRec *clean, FileRec *suspect, FileRec *quarantine);
void purge_all(FileRec **clean, FileRec **suspect, FileRec **quarantine, Sig **sigs);

#endif
