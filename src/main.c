#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file.h"
#include "sig.h"
#include "antivirus.h"
#include "utils.h"

int main() {
    FileRec *clean = NULL, *suspect = NULL, *quarantine = NULL;
    Sig *sigs = NULL;

    printf("=== Toy Antivirus Simulator ===\\n");
    printf("Commands: ADD_SIG, DEL_SIG, LOAD, SCAN, QUAR, RESTORE, REPORT, PURGE, EXIT\\n");

    // TODO: implement simple CLI loop here
    printf("Setup complete. CLI to be implemented.\\n");
    return 0;
}
print itsss
